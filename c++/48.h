
// this is a form of "guard tag" which should prevent duplicate definitions
#pragma once
// this is not supported everywhere (supposedly)

// this is a great example, if we already had this included elsewhere we don't want to include it twice
#include <iostream>

class Player {
    private:
        int health;
    public:
        Player();
        int getHealth();

};

// alternative guard tags:
#ifndef H_48

// we define it so it won't get included again
#define H_48

// we put our definition code here

#endif

