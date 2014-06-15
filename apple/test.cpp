
// this is simply to verify that gcc knows about __APPLE__
#include <iostream>

int main() {

#ifdef __APPLE__
    std::cout << "Yarp" << std::endl;
#endif

    return 0;
}
