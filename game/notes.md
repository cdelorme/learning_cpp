
# game notes

As might be obvious I am working to create an entire game in this section.


## missing components

We still need to add & populate the following abstraction layers:

- map
- physics
- display/rendering
- input
- audio
- logging

For many of these I will start small, adding them to classes they do not belong.

As the class grows and the intentions become more transparent I hope to be able to identify what to separate and how.


### entities, tiles, & maps

I am still trying to understand how to treat these three.

Maps may be fairly strait forward, but I am at a loss for Tiles and Entities, including Player.  Do we need a "Player" class, or can we just create Entities for both players and tiles?

I believe that might end up being the best way to go, but it leads to a great deal of ambiguity.  However, tile interaction may as well lead to maps being comprised entirely of entities.

Controlling rendering order becomes a concern then as well, so I'll need some means of layering for that.


## issues

- Get a proper game loop running
    - implement optional fps restriction to 60 and 30 fps
        - test/verify with fps counter
    - test time-to low-battery% with unlimited, 60, and 30 fps
        - air & retina would be nice

Game loop logic is starting to make sense.  First, setting a maximum framerate allows us to determine the expected FPS.  We use a lag value, the current time minus the previous loops time.  Using a second update loop with logic to keep us there until we are ready to initiate the next render, in otherwords multiple updates may occur per rendered frame, and the leftovers are carried over into the next operation.

The limit is applied to the update logic, not the render logic, which makes the update logic determine the maximum FPS by computer specs.  If a computer is far too slow to run the update, the game simply slows to a halt.

The code appears as:

    elpased = currentTime - previousTime
    lag += elapsed
    while (lag >= FPS) {
        update()
        lag -= FPS;
    }

To support unlimited FPS without setting FPS to some awkwardly high value, we can use 0, and change the >= to >, and set lag to 0 conditionally:

    elpased = currentTime - previousTime
    lag += elapsed
    while (lag > FPS) {
        update()
        lag -= FPS;
        if (FPS == 0) {
            lag = 0
        }
    }

Now we have a loop that only runs once, allowing maximum rendered frames per main-loop iteration.

We can also set a capped amount of iterations by adding a condition before the inner-loop that if lag is greater than X times FPS, we set it to X*FPS to prevent the game from never exiting the inner loop, say due to a terribly slow computer/graphics.

Finally, we can pass residual lag to a render method, which maybe allows movement prior to rendering in order to account for the time-lapse between the render and the next calculation(s).  _I am personally not yet sure how to handle render logic separately from collision detection._  The suggestions are to make corrections later, the extrapolation is preferred even if it is erroneous.

    elpased = currentTime - previousTime
    lag += elapsed
    if (lag > MAX_UPDATES * FPS) {
        lag = MAX_UPDATES * FPS;
    }
    while (lag > FPS) {
        update();
        lag -= FPS;
        if (FPS == 0) {
            lag = 0
        }
    }
    // avoid a divide-by-zero error
    render(FPS > 0 ? lag / FPS : 0);

By passing lag we extrapolate positions without checking whether the movement is 100% accurate (eg. collision detection/rendering engine).  While it may be erroneous, it is usually better than a stutter effect.

If we are worried about power consumption then we may want to do something a bit different inside of our inner loop.  We could just update once per expected frame, and sleep.  Perhaps giving the user a checkbox option for "Power Savings Mode" in addition to lower FPS options would work:

    elpased = currentTime - previousTime
    lag += elapsed
    if (lag > MAX_UPDATES * FPS) {
        lag = MAX_UPDATES * FPS;
    }
    while (lag > FPS) {
        update();
        lag -= FPS;
        if (POWER_SAVINGS_MODE) {
            sf::sleep(lag);
            lag = 0;
        } else if (FPS == 0) {
            lag = 0;
        }
    }
    // avoid a divide-by-zero error
    render(FPS > 0 ? lag / FPS : 0);

**Woops** Don't want to use the approach I had above for MAX_UPDATES, should instead count loops instead, because otherwise we affect the real-time progression when we include lag later.

In fact, the same can be applied to power savings mode and unlimited fps logic.  I really need to rethink this.


- Looking into the best file interaction
    - binary files, global defaults?
    - What about per-game settings?
    - Do we have a single generic config class, or multiple (ex. GameConfig, SaveConfig, InputConfig)

- Implement avg FPS counter
    - add debug hotkey to print fps to screen (can expand on this later)
        - Compare FPS between Air and Retina

- Test window scaling, it would be nice if when the window was resized that the content was still within the bounds with scaling
    - since ratio might matter I'd rather we use a view to maintain ratio and create empty borders

- Figure out the best approach for handling collision detection
    - Also whether we should do one type, or make it dependent on the objects

- Restrict player movement to inside the view

- Identify a means of restricting view scrolling to the BG

- Proper contingent memory pre-allocation (heap allocation maybe?)
    - At the very least, you should pre-allocate and re-use your data objects
    - Pre-allocation of an array of entities for example allows us to request contingent memory, which the CPU can access quicker since it's all stacked together

Reducing the number of classes, such as making Entity serve multiple purposes, allows us to greatly simplify memory assignment, as well as associating the flexibility of generic re-usable objects.  If an entity can represent a map-tile, a player, a monster, and a projectile, we gain loads of flexibility in that respect.  The only cost is explicit definition, or understanding.  However, so far it would appear that most of these can be used in exactly the same way.

Some sort of prototyped object db storage, perhaps even json to binary file, would make for much easier editing in the future (worth noting and perhaps using).  [Check this article out](http://gamedevelopment.tutsplus.com/tutorials/create-custom-binary-file-formats-for-your-games-data--gamedev-206).

An even better idea is [serialization](http://stackoverflow.com/questions/23580513/how-to-create-read-and-write-to-a-custom-binary-file-format-package-images-a).  Serializing pre-built objects and entities allows us to load them that much faster going forward.  Entire pre-built entities could then be loaded without having to do anything too whacky like parse custom-compressed binary files.

