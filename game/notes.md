
# game notes

As might be obvious I am working to create an entire game in this section.


## missing components

We still need the following abstraction layers:

- audio
- input
- physics
- logging
- display/rendering

For many of these I will start small, adding them to classes they do not belong.

As the class grows and the intentions become more transparent I hope to be able to identify what to separate and how.


## issues

- create a more complete game abstraction with separated classes
    - continue to break out all the code as I go along, it'll fall into place if I keep my wits

- Implement avg FPS counter
    - add debug hotkey to print fps to screen (can expand on this later)
        - Compare FPS between Air and Retina

- Test window scaling, it would be nice if when the window was resized that the content was still within the bounds with scaling
    - since ratio might matter I'd rather we use a view to maintain ratio and create empty borders

- Get a proper game loop running
    - implement optional fps restriction to 60 and 30 fps
        - test/verify with fps counter
    - test time-to low-battery% with unlimited, 60, and 30 fps
        - air & retina would be nice

- Figure out the best approach for handling collision detection
    - Also whether we should do one type, or make it dependent on the objects

- Restrict player movement to inside the view

- Identify a means of restricting view scrolling to the BG


## entities, tiles, & maps

I am still trying to understand how to treat these three.

Maps may be fairly strait forward, but I am at a loss for Tiles and Entities, including Player.  Do we need a "Player" class, or can we just create Entities for both players and tiles?

I believe that might end up being the best way to go, but it leads to a great deal of ambiguity.  However, tile interaction may as well lead to maps being comprised entirely of entities.

Controlling rendering order becomes a concern then as well, so I'll need some means of layering for that.

