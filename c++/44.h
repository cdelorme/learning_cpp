
// we can prevent duplicate includes or declarations via "pragma once"
#pragma once

#include <iostream>

class TestClass {
    private:
        int value; // should we not have private and protected in header files?
    public:
        void setValue(int value);
        int getValue();
};

