
# local dynamic linking

This applies to OSX and Linux, and so far I've only had the _pleasure_ of workingn with it on OSX.


## osx

OSX has dylibs, and they contain their own linking information, generally relying on `.framework` elements.

So, by default some compiled sources, such as the SFML libraries, assume they are referencing `../Frameworks/` to find their dependencies, which would make sense if they were part of a `.app` bundle.

If you are not making a `.app` you have to mess with `otool` and `install_name_tool` to change these paths manually.


### `otool`

This is a command that lets you inspect the various properties of a dynamic library file.

Here is an example:

    otool -L libsfml-graphics.2.1.dylib
    libsfml-graphics.2.1.dylib:
        @executable_path/../Frameworks/libsfml-graphics.2.dylib (compatibility version 2.0.0, current version 2.1.0)
        @executable_path/../Frameworks/libsfml-window.2.dylib (compatibility version 2.0.0, current version 2.1.0)
        @executable_path/../Frameworks/libsfml-system.2.dylib (compatibility version 2.0.0, current version 2.1.0)
        @executable_path/../Frameworks/freetype.framework/Versions/A/freetype (compatibility version 17.0.0, current version 17.0.0)
        /System/Library/Frameworks/OpenGL.framework/Versions/A/OpenGL (compatibility version 1.0.0, current version 1.0.0)
        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 111.1.4)
        /System/Library/Frameworks/Foundation.framework/Versions/C/Foundation (compatibility version 300.0.0, current version 677.26.0)
        /System/Library/Frameworks/AppKit.framework/Versions/C/AppKit (compatibility version 45.0.0, current version 949.54.0)
        /System/Library/Frameworks/IOKit.framework/Versions/A/IOKit (compatibility version 1.0.0, current version 275.0.0)
        /System/Library/Frameworks/Carbon.framework/Versions/A/Carbon (compatibility version 2.0.0, current version 136.0.0)
        /usr/lib/libstdc++.6.dylib (compatibility version 7.0.0, current version 56.0.0)
        /usr/lib/libgcc_s.1.dylib (compatibility version 1.0.0, current version 1.0.0)

Using the `-L` we can list the name followed by all dependencies and the expected paths.  Some of these are fine (like the `/usr/` and `/System/` routes), but the relative path to `@executable_path../Frameworks` is intended to be used in an app bundle, where it won't protrude from the actual executables "contents".


### `install_name_tool`

There are two things you may want to modify using this command:

- The id or "name" of the package, which is the first item listed by `otool -L`.
- The `@executable_path` relative paths.

Here is a command to change the id/name:

    install_name_tool -id "@executable_path/something/else/name.dylib" $(otool -XD name.dylib)) real_name.dylib

Here is a command to change a dependent framework path:

    install_name_tool -change "@executable_path../Frameworks/dependent.dylib" "@executable_path/new/path/to/dependent.dylib" name.dylib

_The man pages for this command are actually very useful._


### script

I wrote this script to modify all of the dylibs in a directory, but to use it you have to set the path appropriately:

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
                install_name_tool -change $dlib ${NEWPATH}$tdlib $modlib

            done

            # fix the id/name so that it isn't referring to the symlink of itself in the Frameworks folder
            install_name_tool -id ${NEWPATH}$(basename $(otool -XD $modlib)) $modlib

        fi

    done


## linux

notes pending.

