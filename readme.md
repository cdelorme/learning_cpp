
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



Lots to do:

- Implement FPS counter with debug hotkey for text-to-screen
- Get a proper game loop running
- Figure out the best approach for handling collision detection
    - Also whether we should do one type, or make it dependent on the objects

- Three editors:
    - tile editor
    - map editor
    - entity editor
        - bullets
        - player
        - enemies


References to continue learning:

- [Simple Collision Detection Examples](https://github.com/LaurentGomila/SFML/wiki/Source%3A-Simple-Collision-Detection-for-SFML-2)
- [Collision Aware Tiles](http://www.codingmadeeasy.ca/sourceLayout/display-source?filePath=Source/sfml2/Tut39)
- [SFML Game Tutorial](https://www.youtube.com/playlist?list=PLCB3138ADCE90F2EC)
- [OSX-local sfml docs](file:///usr/local/share/SFML/doc/html/annotated.htm)
- [Fabulous 3D Collision Detection code](http://blog.yoz.sk/2010/11/4-000-000-rectangle-collisions-per-second/)
- [multiple choices](http://www.gamedev.net/page/resources/_/technical/game-programming/the-guide-to-implementing-2d-platformers-r2936)
- [N Docs A](http://www.metanetsoftware.com/technique/tutorialA.html)
- [N Docs B](http://www.metanetsoftware.com/technique/tutorialB.html)
- [Game Loop](http://gameprogrammingpatterns.com/game-loop.html)
- [fix gamestep](http://gafferongames.com/game-physics/fix-your-timestep/)


The N docs are supposedly amazing, and the game programming patterns probably has the answer I need for writing a suitable game loop.

Tiles have many types of player interaction which can make them a bit complex:

- Solid (can't walk or fall through)
- Breakable (can be destroyed with an attack)
- Moveable (think puzzle game blocks)
- Moving (elevators)
- One-Way (Jump up through, optionally down, but won't fall automatically)
- Damage (Spikes, Lava, Water in a game withotu swimming)

---

Animated tiles become all the more confusing.  If you have a tile that has independent animation then we need to do something about it.

If you use tiles of variable size you add a massive amount of complexity to the overall game.

Parallax background handling.


---

Detailed or oddly shaped character sprites make it much harder to cleanly handle collisions.  The bounding box method becomes unfair in the eyes of a player, and the work-arounds are limited:

- Pixel Perfect Detection (slow, creates or uses a bitmask to compare every pixel)
- Multiple Boxes /w Bounding Box Collision Detection

For performance you want to probably pick the most efficient method per object, in a game with dozens of on-screen enemies pixel perfect can be a serious issue.







## Add these notes to my learning_cpp docs someplace:

You can convert mp3 to ogg from command line.  It's not exactly clear how the commands should work, so here is some documentation.

The following command will create an ogg container, but the audio format will be flac, which is massive:

    ffmpeg -i my.mp3 -vn my.ogg

To properly compress it you need to set the audio codev, and also eliminate strict mode because vorbis is experimental:

    ffmpeg -i my.ogg -codec:a vorbis -strict -2 my.ogg

So, the do it all in one go you have the following:

    ffmpeg -i my.mpv -vn -codec:a vorbis -strict -2 my.ogg

