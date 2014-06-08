
#include <iostream>

// global variable example
int variable = 5;

int main() {

    // we can create local to override global
    int variable = 10;

    // we will get the local variable
    std::cout << variable << std::endl;

    // to access the global we just use the unary scope operator
    std::cout << ::variable << std::endl;

    // basically, :: is the current scope aka "global namespace"

    return 0;
}

