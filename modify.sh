#!/bin/bash

# define the new path
NEWPATH="@executable_path/lib/"

# grab all the dylibs
DYLIBS=./*.dylib

# iterate all the libs we want to modify
for modlib in $DYLIBS
do

    # don't modify the symlinks, only the actual files
    if [ ! -L $modlib ]
    then

        # grab the dependencies per .dylib
        DEPS=$(otool -L $modlib | grep "\.\./Frameworks" | awk -F' ' '{ print $1 }')

        # loop to fix
        for dlib in $DEPS
        do

            # fix it's dependencies
            tdlib=$(echo $dlib | sed 's/@executable_path\/..\/Frameworks\///')
            #echo install_name_tool -change $dlib ${NEWPATH}$tdlib $modlib
            install_name_tool -change $dlib ${NEWPATH}$tdlib $modlib

        done

        # fix the id/name so that it isn't referring to the symlink of itself in the Frameworks folder
        #echo install_name_tool -id ${NEWPATH}$(basename $(otool -XD $modlib)) $modlib
        install_name_tool -id ${NEWPATH}$(basename $(otool -XD $modlib)) $modlib

        # finish up by printing the results
        otool -L $modlib

    fi

done
