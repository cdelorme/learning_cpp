
#include <iostream>

namespace one {

    // main cannot run from inside of a namespace
    // this will throw exceptions if no actual main is defined outside
    int main() {

        std::cout << "Hello World" << std::endl;

        return 0;
    }
}

using namespace one;

int main() {
    std::cout << "Not inside a namespace" << std::endl;

    return 0;
}

