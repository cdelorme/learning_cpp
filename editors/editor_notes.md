
# editor notes

We need a few editors:

- Tile Editor
- Map Editor
- Entity Editor
- Audio Editor

Individual tiles are defined in the tile editor, and then placed onto a map using the map editor.

The entity editor is for player and enemy sprites, though I may end up making them part of the tile editor.

The audio editor isn't even a thought-in-progress as of yet, but the idea would be to match audio tracks with a readable name, which may help if we don't want to organize them in the file system sensibly.


## editor formats

For swift debugging we should support both text and binary file formats.  An optional checkbox for debug mode to change read and write operations to use raw text instead of binary.

The `fstream` flags are like so:

    ios::in | ios::binary


## maps

Maps should have:

- Tiles
- One or more background images /w parallax support
- an optional musical track

Another question is whether we have a bunch of separated maps with entrances (and possibly loading screens), or if we want to load one entire map of the whole game up front.  Is it possible to handle the entire game map all at once?  How would we handle transitions is another good question.

Also, do we expect all map tiles to be the same size?  This would add to the complexity in every way if we allowed multiple block sizes.

Do we also want to slow down the players movement when climbing a slope, and increase it when descending a slope?


## animation

Entities certainly have animation loops, but it is also possible that every on-screen tile may also have an animation loop.  This is going further and further towards tiles being entities, and vice-versa.


## tiles

Tiles have many types of player interaction which can make them a bit complex:

- Background (could be air, or theme objects)
- Solid (can't walk or fall through)
- Foreground (same as background, but drawn in front of the user)
- Breakable (can be destroyed with an attack)
- Moveable (think puzzle game blocks)
- Moving (elevators)
- One-Way (Jump up through, optionally down, but won't fall automatically)
- Damage (Spikes, Lava, Water in a game withotu swimming)


Known tile attributes:

- dimensions (width, height)
- `position_in_image` (top, left)
- image_name
    - texture (for buffering)
    - sprite (for rendering, uses position and dimensions for parts)

_Animation support adds to complexity._


## collision detection

Here are some options:

- Bounding Box (Traditional, high performance poor accuracy with rounded edges)
- Distance (OK Performance, much better for round objects accuracy)
- Pixel Perfect (low performace, 100% accurate)
- Multi-Bounding Box (Combines multiple bounding boxes per entity making it higher performance but also more accurate)

I still have a lot of research to do, especially on how to handle slopes.


Detailed or oddly shaped character sprites make it much harder to cleanly handle collisions.  The bounding box method becomes unfair in the eyes of the player.

However, we want to pick a balance of high performance and high accuracy if possible.

