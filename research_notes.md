

## [SFML New Concepts to apply!](http://www.reddit.com/r/gamedev/comments/1ue3h3/tile_based_levelsmaps/)

Consider composition to reduce memory hogging objects, and re-using the same data structures.

Use an Entity for every unique instance of a graphical object.  One for each monster, each player, and each map tile.

Each item drawn on screen would then need its own logic.  For example it may make sense to use a dirty-bit or a "Visible" flag to determine whether to draw it, so we aren't drawing enemies off screen (or at least too-far off screen).


## [SFML Tile Map example at bottom](http://www.sfml-dev.org/tutorials/2.1/graphics-vertex-array.php)

This document has tons of useful info.

1. There are three major types of `sf::Vector2` objects.  There is 2i for integer, 2f for float, and 2u for unsigned integer.  It would be very smart to use 2u when you are not intending to have negative values.

2. It turns out that tile maps have a maximum size based on the graphics driver!  This introduces a whole new issue, because as mentioned elsewhere some poor performing drivers are as small as 512x512 pixels.  I need to plan on either distributing all images independently, or a method of breaking down images for loading at run-time.  The method to get the maximum size is `sf::Texture::getMaximumSize()`.

3. Vertex Arrays and Quads may not help with animated maps or tile maps so much.

4. For big background maps, breaking it into textures by max size would work best for storage and maybe rendering, but smaller sizes might help reduce the amount of rendering that occurs outside of the screen size.

5. It is possible to define custom sizes per tile, and not too much more complex for rendering.

6. We have the option of rendering everything visible or maintaining a resolution ratio on resize, I am all for increasing the visible content, but in versus games that may create unfair advantages to those with bigger resolutions, multiple monitors, and beefier graphics cards.  IMO they deserve that advantage, they paid money for it to their hardware manufacturer(s).  #lifesnotfair


Separate files is dumb, because we end up disk thrashing with heavy IO at load time.  Instead, we should have a single sprite-sheet, and the data for our data should specify there specs.  We want to load the single file once into an `sf::Image` object, this way we aren't killing IO by loading from file every texture.  Each texture should use `sf::LoadFromImage` and pass a second argument, an `sf::IntRect` which specifies the top, left, height, and width.  This will work perfectly fine for images within the `getMaximumSize` constraints, but for data maps greater than that size we need additional details such as the height and width of individual frames, so that we can break down the data into multiple textures.  Mapping those entities is going to be a massive pain.

Specs for texture mapping with data should consist of top, left (on the sprite sheet), height, width, and for further breakdown (say an object above the min expected size of 512x512) we use


We can use `VideoMode::GetDesktopMode()` to get the resolution of the screen, which may help us determine the best median for rendering, which would work in the current window size, up to the larger size.

We can use the `TileMap` example class instead as a `MapTile` class, which then is used in composite to break down a structure into multiple tiles of the maximum allowable, or most performant, size.  It will be tricky writing a library with multiple drawable surfaces, but perhaps that is exactly what we need to reduce inheritence, the `MapTile` may only have `sf::Transforable` and the owner may have `sf::Drawable`?  Multiple vertex arrays, feels like I'm already preparing for 3D drawing lol.


Ideally, I should try my own ideas as well and check the performance between them and the SFML "way".  The easiest test for this would be having FPS displayed while trying a background image with multiple frames.  My method would be to skip VertexArrays and just have a set of "Tiles", which are max-size textures, and draw the visible items.  The second would tear down the work into a vertex array per texture, and allow for more finely tuned rendering.  The assumption is that pre-rendered quads should display faster, but to test it is another story.




## [Super Hardcore Editors](https://www.youtube.com/watch?v=hSZXTrpYroA)

To build a complete entity and map editor in SFML will be quite difficult, because they do not currently have any sort of standard interface library with controls or themes to match the operating system.

To reduce the work, I may have to look at either a separate windowing libary for the editor, some combination of them, or I can use a [third party library](http://sfgui.sfml-dev.de/), which employs the zlib license, so it is open source and free for use in open and closed source projects.  I only have to include their license with the source code, I can exclude it if I release a binary.


## [Dirty Bits](http://gameprogrammingpatterns.com/dirty-flag.html)

I should really read through this and see if the pattern makes sense for rendering drawing content.

If I can dirty-flag anything that is on-screen for the next rendering cycle that'd be sweet, or even better create a wider-area beyond the size of the screen so that we have already begun rendering it for the near-future?

Wow awesome, so the idea behind the dirty bit is to set it on a parent object, not every child.  That makes more sense.  This obviously is only necessary in very large constructs, which makes way more sense for 3D, in my 2D map scenario probably not necessary.

There is another use!  If you want off-screen data to continue to be processed but not rendered, a dirty bit allows you to defer the rendering changes until it's on-screen again.  Ideally this means two to three things could effect a dirtybit.  The Collision Detection, AI processing, and Physics Engine (with a full physics engine you may not have separate collision detection).


## [Raw OpenGL](http://stackoverflow.com/questions/5720520/opengl-wont-draw-my-quad)

I could always also look into direct OpenGL rendering commands in C++.  It does not look all that much harder, but I'm sure it's a lot less abstracted that SFML and I would be recoding half of what their library does for me.

- [pitfalls](http://www.opengl.org/archives/resources/features/KilgardTechniques/oglpitfall/)

When I get to raw 3D graphics I think I'll take a look, but not yet, and possibly not for a while.




## [Collision Detection Tools of the Trade](http://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-basics-and-impulse-resolution--gamedev-6331)

- [SAT](http://gamedevelopment.tutsplus.com/tutorials/collision-detection-with-the-separating-axis-theorem--gamedev-169)

The SAT example is freaking awesome, it'll make my basic collision detection a snap.  Later on I can move into the scarier realms of detection, but my first game all the blocks will be properly aligned.

Bounding boxes can include two points, or the top-left and height-width.  The height and width will need to be used to get the bottom right eventually, so it's a question of efficient and necessity.

Mass, velocity, and position should be taken into account with collision resolution.

Besides bounding boxes, we may want to also employ circles.  I'll have to decide what makes sense sometime soon, but if I can use both and combine the logic that does the checks properly that'd be great.

Additional constructs to collision handling include friction and "bounciness".  Friction plus max speeds determine how quickly velocity is reduced once force is no longer applied/  Low friction means an object can continue moving quite a while, high friction means it slows down quickly.  No friction is the same as 100% friction, in that the moment the user stops pressing the movement key the object halts.



## [All About Vectors](http://www.mathsisfun.com/algebra/vectors.html)

This is important maths!

Vectors can be described as [a direction + a magnitude].

In programming they are described as two points.

Common vector basics in programming include not only two point vectors, but multiple point vectors creating basic shapes, like "Quads" or "Triangles" are commonly used to simplify drawing (Quads are preferred these days).

Scalars are decimals that can be applied to the magnitude, and the resulting effect is "Scaling a Vector" or "To Scale".

So, Scalars & Vectors make up almost all of graphics from the point of view of a computer.  It's not near as simple when comparing hand-drawings to vectors, because the vector equivalent is often many times more complex.

Also worth noting is that vectors can apply to basic 2D as well as 3D graphics.  As previously mentioned, computers describe them as two points.  In 2D space that's an x and y axis, in 3D space it's an x, y, and z axis.

More complex uses of vector math are to calculate applied force on an object to figure out it's new vector of movement.


## [Broad Phase Collision](http://www.metanetsoftware.com/technique/tutorialB.html)

This is the practice of identifying tiles in-range of your object to check against, instead of checking against literally every object on the map.

It starts with breaking up the map of tiles into a grid of square cells (size can be determined dynamically).  Any cells touching our player or monster entities are then checked for collisions per routine.

The approach used by N fails if any entities or objects in the game are larger than a "cell".  This is to keep things performing well.

I plan to follow a sub-set of similar practices, but using more complex structures, including support for entities with larger bodies, and multiple bounding boxes to define them.  I will still use an algorithm to determine relative tiles to compare against instead of the entire map, but the efficiently of checking that per non-map entity on-screen will vary.

For the very basic check, we verify the tiles that contain the coordinations of the four corners of one or more bounding boxes.  This should be fairly easy.

If a very large entity has fewer bounding boxes it becomes much harder to check related tiles.  You would have to run an algorithm to get the extremes of its four corners, then identify the entire range of tiles between those four points.

One suggestion is to mark edges of tiles so that quicker calculations can be made.  For example, solid, vs interesting, where solid can be used to kick objects out of the edge without any complex collision routines, and interesting primes us to know we have to perform additional collision routines.

At the very least, storing a flag of whether a cell contains any solids would be a good start.  Since we have enemies in this game, we also need to check cells for enemies, not just solids.  Empty cells can be easily skipped by the collision routines, maybe speeding up the performing a bit.

Communication between world and entity to identify collisioned cells.  The world should accept the user object, read its bounding-box positional data, and produce the collision tiles.  The ideal scenario is we call window.collide(entity), and the collide method calls entity.collide(&tiles).  We might be able to also check for enemies in the same collision cells to send to the collide function.

Another option is to store an array of enemies inside any given tile, which we can then check during the tile collison tests, in addition to the "isEmpty" flag to skip tile-collision checks.


## Ray Casting

This is more likely to be used in AI formulas, but we can determine a line-of-sight with this technique, and then let the monster AI choose whether to chase or run from the player.

Depending on the AI type we may have things like "Trackers", "On-Sight-Only", or "Passive-Aggressive", or "Flee".  The AI level can also determine things like whether they keep their train-of-thought or choose to delay their primary actions.


## Projection for multiple entities

There may be some edge cases for multiple enemies on screen, depending on how they interact with eachother, or with the player and the order of rendering.

We need separate loops to check player vs entities, then entities versus tiles.

This is so that if a player is touching a monster, they both are projected away a good distance for damage effect (and to prevent instant death lol).  However, then we need to check the player and monster now for tile collisions.

I suppose if we do that order for each entity it'd be fine.


## [Finally the most Efficient Collision Detection](http://www.metanetsoftware.com/technique/tutorialA.html)

Using the SAT method for AABB vs AABB requires only 2 axis points be compared, x and y.

Right angle triangles with an x/y axis alignment can be compared with only one more axis perpendicular to it's third non-aligned side.  The math for this might be tricky, but it will allow near-perfect handling of slopes.

The "Projection Vector" is the shortest distance "Escape Route" from the collision.  Ideally if equal you should escape top-wise.  If your game has death falls you may consider a slightly biased calculation, such as a 3:5 ratio or 5:8, to prevent minor misteps resulting in death.

Round shape collision can actually be handled almost identically to triangle collision with a single third axis.  That axis uses a center and the opposite radius relative to the compared box to determine a third point, which allows us to create the perpendicular line for the same comparison.

_Dealing with convace circles will be tough.  That's where there is an inner slope._  They claim that they deal with concave shapes by checking if the center of the circlular chunk that is missing is inside of the box, if not they apply the traditional projection algorithms.

Technically this also means any shapes with more sides just adds one more axis per side to compare.


**Axis Theorum for Circles**

In theory it's alright, but it's flawed at corners sometimes.  In cases where the center of the circle is outside the range of the parallel lines, it's entirely inaccurate.

Therefore we have another thing to learn about!


**Voronoi Regions**

These are regions closest to an edge or vertex of a polygon.

We can use it on triangles, and squares to identify regions outside of our parallel edges.  Then when an object like a circle approaches with a radius outside of our parallel edges, we can add a third axis to check.



**Awkward edge cases**

Let's say you have a low ceiling and floor, the player can't fit through, but the ceiling is at a slope.  Depending on the order of objects the collision detection uses, your player could end up stuck in the ceiling, or the floor.

Another concern is problems with points and projection.  If the objects are moving very fast per frame the collision routine may determine what seems like an invalid projection.  Say a ball is falling really fast and hits a corner, by the time the collision is caught it is far enough down that the reoutine decides it's best to push it out the side.

Two ways to deal with fast moving objects are "Swept Collision" and "Multi-Sampling".  Sweeping is the process of creating a block along the path of an object and checking for upcoming collisions.  Multi-sampling is preferred, it is where for very fast moving things you calculate multiple points between the radius and heading/direction.  In this way you can capture upcoming collisions and respond to them quicker.



## N graciously provided their source code for all their examples, it's pretty sweet.

**Techniques**

The use of "Early-Out" techniques is smart, because it reduces the necessary calculations.  I suspect complex structures to have multiple bounding boxes, and therefore

**Phsyics handling ontop of this will require significantly more reading.**



## simpler menus

I was watching the "Made Easy" videos and the fourth video of the MenuManager portion of the SFML Platformer tutorial was a great indicator that a menu does not have to be complex.

Literally a black screen with text rendered to match the menu is all that is necessary.

Even more versatile if the menu text is loaded from a file (because it can then be swapped out per language).

A means of determining the index both in code, and visually by changing opacity at runtime (eg. focus/blur effect back and forth or vivid to dim back and fourth).  The final step of each menu would be tied to specific events or actions.

The only tough part here might be loading save data, but that's only a bit more complex than loading a text-file for menu items.

