
We need a few things:

Tile Editor - For editing Tiles
Map Editor - For editing Maps (which use Tiles)

We need to have support for reading and writing both binary and text.  Some kind of optional debug mode to save or read data as text vs binary, allowing us to quickly convert all the text to compatible binary files and reverse, for testing.

We can add the binary flag to in (or out) in our fstream:

    ios::in | ios::binary



Some major questions:

- How do we describe tiles?
- How do we describe maps?

**This will have a heavy influence on the games collision detection.**

Some standard collision tests include:

- Bounding Box
- Distance
- Pixel

Bounding box is great for simplicity, but it's hardly accurate, especially if the boxes that make up your graphics are very detailed.  They are simple enough to check for which makes them performant, and a wonderful pick for things like RPG's or strategy games that don't need a high degree of collision accuracy.  It doesn't give you the power to do things like slope collisions, and that can greatly limit even a 2D platformer.

Distance collision uses more line based math with a radius instead of a box.  It's another option if you have rounder elements to define.

Pixel perfect collision eats your CPU up and is not ideal in almost any case.  However it is the most accurate collision detection.  In the CodingMadeEasy example he converted all of his sprites to images, and mapped the pixels for comparison, identifying any pixels with alpha > 0.  The approach used combines the bounding-box check with pixel-perfect comparison.  The good news is that makes it pretty easy to implement only on some elements.  It can identify bounding box collisions, and limit comparison to the overlapping sections.


- [Good read](http://www.gamedev.net/page/resources/_/technical/game-programming/the-guide-to-implementing-2d-platformers-r2936)
- [more good reads](http://www.metanetsoftware.com/technique/tutorialA.html)
- [again](http://www.metanetsoftware.com/technique/tutorialB.html)



Obviously a tile would have a size, the name of the image in which it exists, and its coordinates on that image (can be 0,0 or for multi-image sprite mapping could be diff).

However, going beyond this it may also have additional bits to represent certain types of data.  For example, is it solid or air, does it maybe have a slope or inner curve?  Does it have spikes that maybe do damage?  Or perhaps it is lava, or water?  Is it single-directional such that you can jump up but won't fall back through (and will your game allow crouched jump to go back down)?

This is where simple bounding box collision detection may not be enough to make all of this work, and some creativity has to be included.



---


What about maps?

Obviously a map consists of a bunch of tiles.  However, in addition to the tiles, a map may also have additional bits for important things, like which spots enemies will spawn, and maybe doors that lead to other areas.

Another good question is where the platformer I build will be treated as one giant map and simply change which tiles are loaded as the player moves around?  Or will it be loading screens between areas type travel?

How do we handle the transision so the user knows if there is no loading screens?


Another good question is whether we want to slow or speed the character movement while climbing or descending a slope?

