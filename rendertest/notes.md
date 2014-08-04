
# render test

This is a test that uses the data from [this document](http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array.php).

The objective is to test and compare rendering a tilemap from sprites ontop of textures, versus quads using textures in a vertexarray.

In future iterations I would like to experiment with loading images significantly larger than the maximum texture size limit, and breaking it into smaller chunks that can be handled by any graphics card.  However, this may not be necessary if designing towards modern cards, of which even mobile devices seem to have a maximum of 512x512 as-is.  Also, the concept that textures are applied to 3D space is still a bit of a mystery for me, so that'll be worth testing out sometime too.

## raw fps test

- open a window
- conditionally calculate fps
- render fps
- display & clear

_This adds the bar for us to run our tests against, by defining what the absolute fastest render speed can be when no actual rendering work is done (beyond fps), in contrast to simply comparing a higher and lower number from the next two._


## sprites test

- load the texture
- create an array of 1024 sprites, randomly assigning each an index for the texture tile
- use this array to populate a 32x32 map (tile size of 32x32 pixels, so 1024x1024 window size)
- load a text object to display fps
- run the render loop to draw the sprites
- conditionally update FPS once per second
- draw fps


## quads test

- load the texture
- load an array of quads to map to the textures
- load a text object to display fps
- run the render loop to draw the vertex-array of quads
- conditionally update fps once per second
- draw fps


# results

Running on the Core i7 3770's integrated Intel HD 4000, the raw fps was approx. 500.  Both "real" test cases held over 350 frames per second.  To my surprise the sprites were actually significantly faster than the quads (on average more than 50 fps faster).  To explain this I noticed less than 5% CPU while running the quads test, and over 20% CPU while running the sprites.  In both cases system memory used was negligable (though my test system has 32GB so there could still be a significant difference).

Running on a Macbook Air's Dual-Core i7 with integrated HD 5000 the raw FPS averaged 1500~, with the sprite test yielding 600~ fps and the quads at over 1000 fps.  This contradicts the results of the HD 4000, indicating that the more powerful the graphics card the better it performs with quads.  Further the CPU on the dual-core i7 was at 40% while running the sprites test and 30% while running quads, which yields yet another reason to use quads.  The memory consumption between the two only differed by 1 Megabyte, with numbers of 10MB and 9MB respectively.

**In conclusion, quads are the superior choice for CPU consumption as well as FPS on powerful integrated or discrete graphics cards.**


## questions I asked myself

- how do I load a texture if the image exceeds the maximum size?
- if our entities are significantly smaller than the tiles are, what impact would that have on collision detection?
- is it beneficial for quads and textures to be larger or smaller?
- should the engine support variable sizes or as non-square shapes?
- should we have a render-size setting (eg. viewport) and scale that to fit the window size (retaining ratio)?
- should we allow individual entities to have an alternate default-scale (eg. **not** 1)?
- can we use the maximum tile size, the desktop resolution, and the pixel-tile-size in some way to render more efficiently?
- what is the most efficient way to handle metadata and map it to textures?
- how can we handle animated backgrounds?


### answers I came up with after reading and thinking

Trying to load sf::Texture from files greater than the maximum texture size will fail.  Instead, load the content into `sf::Image` first, then create textures to grab chunks from the image.  _I assume the textures load into the graphics card, while images just load into system memory/RAM._

For pixel-perfect collision larger tiles will decrease performance due to the number of pixels to be checked (although this can be alleviated if additional quadrant narrowing is performed within the collision logic before comparing pixels).  For bounding-box collision the performance remain about the same, since the formulas to run the check should be unchanged.  In both cases the larger tiles reduces the chance of a smaller entity existing accross 2 or more, which can lead to an increase in performance for both scenarios.

This is context sensative, for example whether a texture or quad will be used often and how many others are loaded.  _It appears that textures load into graphics memory, which means too many textures or very large textures can be a bad thing._  However, if a single large texture is re-used in many places, then a single larger texture may be beneficial over many smaller textures.

Sizes should be fixed values, based on a pre-determined restriction.  Dynamic sizing would add a lot of complexity for little overall gain, even in the case of 3D.  Supporting shapes of multiple sizes makes it very difficult to perform any amount of tiled mapping sensibly, and in no case can larger graphics not be cut into smaller segments to fit a standard size.

Introducing a render-size would be a great start, but to handle stretching with SFML you would want to use a viewport, otherwise resizing a RenderWindow will stretch the contents ignoring aspect ratio (see [here](http://en.sfml-dev.org/forums/index.php?topic=11032.0) and [here](https://github.com/eXpl0it3r/TileMapCreator/blob/master/src/Application.cpp#L93) and [here](http://www.sfml-dev.org/tutorials/2.0/graphics-view.php) for solutions).

It would be increasingly complex to add layered scaling and allow entities to have their own overridable scale.  Stretching graphics reduces the clarity of them, and can be done to the images manually instead of inside the application.  Two ways I can think of are overriding the scale() method to execute a setScale() first, or apply floating point math to add two percents separately to perform the operation (leading to possible inaccuracies).  Alternatively would be to track the last size to perform floating point calculations each time (which could lead to inaccuracies with repeated operations).

In general there isn't a way to use the maximum tile size, or current resolution to increase the efficiency of rendering, but it may help when dealing with graphics cards that have a significantly lower max texture size.  However, modern mobile devices have a standard of 2048x2048, already well beyond the standard screen resolutions on FHD displays, which to me indicates that even if we chose a whopping 512x512 default texture tile size it would probably function on most devices made within the last decade.  Therefore any considerations I had around this concept will probably be scrapped.

---

Metadata mapping is a difficult subject.  Without a standard-format for the images, the tiles could be anywhere in a texture.  For example, we could enforce movement animation with 4 directions, maybe 3 frames each, and a standard layout (rows/columns).  However, what about if some things have more than a dozen frames, or maybe we need to add various attacks, jumping, and other movement types into the mix?

[metadata example](http://gamedev.stackexchange.com/questions/22772/how-can-i-handle-sprite-sheets-with-nonuniform-sprite-dimensions)


## other docs to read

- [transformations tutorial](http://www.sfml-dev.org/tutorials/2.1/graphics-transform.php)

If I want to build anything without SFML, I will need to know how to handle transformations.  Primarily positions and scales.

