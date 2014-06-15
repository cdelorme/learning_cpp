
# learning c++

Exactly as it is titled, this is a bunch of test cases to step-by-step learn various parts of c++.

This repository contains some notes in my own words as a personal reference in the future.

Finished watching and writing a bunch of C++ and SFML tutorials and test cases.

Next up is the [CodingMadeEasy SFML Platformer Tutorial](https://www.youtube.com/playlist?list=PLCB3138ADCE90F2EC), which I will check out hopefully soon.

I also have my own list of interests to invest some time into.


## tasklist

- Implement avg FPS counter
    - add debug hotkey to print fps to screen (can expand on this later)
        - Compare FPS between Air and Retina

- Get a proper game loop running
    - implement optional fps restriction to 60 and 30 fps
        - test/verify with fps counter
    - test time-to low-battery% with unlimited, 60, and 30 fps
        - air & retina would be nice

- Figure out the best approach for handling collision detection
    - Also whether we should do one type, or make it dependent on the objects

- Restrict player movement to inside the view

- Identify a means of restricting view scrolling to the BG

---

- Three editors:
    - tile editor
    - map editor
    - entity editor
        - bullets
        - player
        - enemies

_the tile editor may in fact be an entity editor in disguise._

---

- Research AI for enemies, and how to vary difficulty

---

- C++ Dirwalk /w sha256 hash generation for "simple" file deduplication
    - Group by size, then perform hashing in sets by size where items > 1?


## references

- [CodingMadeEasy SFML Platformer Tutorial](https://www.youtube.com/playlist?list=PLCB3138ADCE90F2EC)
- [Locally installed SFML docs OSX/Linux](file:///usr/local/share/SFML/doc/html/annotated.htm)

- [Building .app bundles](http://stackoverflow.com/questions/1596945/building-osx-app-bundle)
- [Scripted bundle generation](http://wiki.lazarus.freepascal.org/Application_Bundle)
- [Relative data files from app bundles](http://stackoverflow.com/questions/516200/relative-paths-not-working-in-xcode-c)

- [Simple collision detection examples](https://github.com/LaurentGomila/SFML/wiki/Source%3A-Simple-Collision-Detection-for-SFML-2)
- [Collision aware tiles](http://www.codingmadeeasy.ca/sourceLayout/display-source?filePath=Source/sfml2/Tut39)
- [Various collision detection methods explained](http://www.gamedev.net/page/resources/_/technical/game-programming/the-guide-to-implementing-2d-platformers-r2936)
- [N docs A](http://www.metanetsoftware.com/technique/tutorialA.html)
- [N docs B](http://www.metanetsoftware.com/technique/tutorialB.html)

- [fix gamestep](http://gafferongames.com/game-physics/fix-your-timestep/)
- [Game Loop](http://gameprogrammingpatterns.com/game-loop.html)

- [Fabulous 3D Collision Detection code](http://blog.yoz.sk/2010/11/4-000-000-rectangle-collisions-per-second/)

