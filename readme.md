
# learning c++

Exactly as it is titled, this is a bunch of test cases to step-by-step learn various parts of c++.

This repository contains some notes in my own words as a personal reference in the future.

I began following the [CodingMadeEasy](https://www.youtube.com/user/CodingMadeEasy/playlists) video tutorials.

The first half of the c++ section was like a refresher course supplementing my college class, but there was some good stuff in them.

I am now working my way through the [sfml](http://www.sfml-dev.org/) tutorial (as an alternative to SDL with OpenGL on my mind).  I am enjoying it quite a bit, and next I will be following the platformer tutorial.


# references


This might help me create a .app from my project files:

- [compiling with .app info](https://developer.apple.com/library/mac/documentation/porting/conceptual/portingunix/compiling/compiling.html)
- [more on dynamic lib programming](https://developer.apple.com/library/mac/documentation/DeveloperTools/Conceptual/DynamicLibraries/000-Introduction/Introduction.html#//apple_ref/doc/uid/TP40001869)

Something like this mayhaps?

    gcc -bundle a.o b.o c.o -o mybundle.bundle \
        -bundle_loader /Applications/MyApp.app/Contents/MacOS/MyApp

- [Finally, a useful link](http://stackoverflow.com/questions/1596945/building-osx-app-bundle)
- [bundle structure](https://developer.apple.com/library/mac/documentation/CoreFoundation/Conceptual/CFBundles/BundleTypes/BundleTypes.html)
- [Info.plist structure](https://developer.apple.com/library/ios/documentation/general/Reference/InfoPlistKeyReference/Introduction/Introduction.html)
- [Actual Info.plist table](https://developer.apple.com/library/ios/documentation/general/Reference/InfoPlistKeyReference/Articles/CoreFoundationKeys.html#//apple_ref/doc/uid/20001431-110725)
- [automated script to create app bundle](http://wiki.lazarus.freepascal.org/Application_Bundle)
- [Still looking up referencing data files from app file](http://stackoverflow.com/questions/516200/relative-paths-not-working-in-xcode-c)
- [Looks like I gotta do this the dirty way](http://en.sfml-dev.org/forums/index.php?topic=9146.0)

