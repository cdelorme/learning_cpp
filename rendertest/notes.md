
# render test

This is a test that uses the data from [this document](http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array.php).

The objective is to compare rendering speeds between multiple sprites from textures, versus textures to quads via vertexarray.

Both sets of code should:

- get the current screen resolution as the display-size
- open a window to that size
- prepare a text-render of the FPS, to judge (via last-5-average)
- get the maximum texture size (per-gpu), and dynamically decide on an appropriate tile-size within that maximum
- load an extremely large texture, breaking it up by "tile-size"
- calculate fps
- draw background then fps


**Here are the key differences!**

SpriteTest:

- dynamically loads a sprite per texture as a "tile"
- draws the tiles in a loop

VertextArrayQuadsTest:

_Still working on this one._
