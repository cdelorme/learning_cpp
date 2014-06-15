#!/bin/bash
# Create a custom app

# accept app name via command line
appfile=$1

# uppercase first character for app name
appname=$(echo $appfile | head -c 1 | tr [a-z] [A-Z]; echo $appfile | cut -c 2-)

appfolder=$appname.app
macosfolder=$appfolder/Contents/MacOS
plistfile=$appfolder/Contents/Info.plist
PkgInfoContents="$appname#"

# optional folders
frameworks="lib/"
data="data/"

# if no executable then exit
if ! [ -x $appfile ]
then
    echo "no appfile found"
    exit 1
fi

# build directories with recursive parent construction
mkdir -p $macosfolder
mkdir -p $appfolder/Contents/Resources
mkdir -p $appfolder/Contents/Frameworks

# For debugging you can set the app as a symlink to the executable
if [ $1 = "debug" ]
then
    ln -s "../../../${appname}" "${macosfolder}/${appname}"
else
    # mv instead of cp is an option as well
    cp "$appname" "$macosfolder/$appname"
fi

# copy frameworks
if [ -d "${frameworks}" ]
then
    cp -R "${frameworks}" "${appfolder}/"
fi

# copy data
if [ -d "${data}" ]
then
    cp -R "${data}" "${appfolder}/Contents/Resources/"
fi

# copy docs
if [ -d "docs/" ]
then
    cp -R "docs/" "${appfolder}/Contents/Resources/"
fi

# copy icon if named as appfile and png
if [ -f "${appfile}.png" ]
then
    cp -R "${appfile}.png" "${appfolder}/Contents/Resources/"
fi

# Create PkgInfo file
  echo $PkgInfoContents >$appfolder/Contents/PkgInfo

# Create Info.plist
echo '<?xml version="1.0" encoding="UTF-8"?>' >$plistfile
echo '<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">' >>$plistfile
echo '<plist version="1.0">' >>$plistfile
echo '    <dict>' >>$plistfile
echo '        <key>CFBundleDevelopmentRegion</key>' >>$plistfile
echo '        <string>English</string>' >>$plistfile
echo '        <key>CFBundleExecutable</key>' >>$plistfile
echo '        <string>'$appname'</string>' >>$plistfile
echo '        <key>CFBundleIconFile</key>' >>$plistfile
echo '        <string>'$appname'.png</string>' >>$plistfile
echo '        <key>CFBundleIdentifier</key>' >>$plistfile
echo '        <string>com.caseydelorme.'$appname'</string>' >>$plistfile
echo '        <key>CFBundleInfoDictionaryVersion</key>' >>$plistfile
echo '        <string>6.0</string>' >>$plistfile
echo '        <key>CFBundlePackageType</key>' >>$plistfile
echo '        <string>APPL</string>' >>$plistfile
echo '        <key>CFBundleSignature</key>' >>$plistfile
echo '        <string>'$PkgInfoContents'</string>' >>$plistfile
echo '        <key>CFBundleVersion</key>' >>$plistfile
echo '        <string>1.0</string>' >>$plistfile
echo '    </dict>' >>$plistfile
echo '</plist>' >>$plistfile
