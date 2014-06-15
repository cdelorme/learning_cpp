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

        # finish up by printing the results
        otool -L $modlib

    fi

done
