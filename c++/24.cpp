
#include <iostream>

using namespace std;

int main() {

    // when we define a variable it creates a space in memory to store the value
    int healthAmount = 100;

    // however, it also creates a memory address aka a "pointer" to where the value is in memory
    // we can use a pointer variable to identify that address, via deference for example
    int *health = &healthAmount;

    // we can then use this pointer to access and modify the memory at that address
    *health -= 20;

    // we can then see both the pointer address and the value in memory
    cout << health << endl;
    cout << *health << endl;

    return 0;
}

