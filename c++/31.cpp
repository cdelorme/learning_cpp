
#include <iostream>

using namespace std;

int main() {

    // dynamic memory allows us more direct access to place content in memory

    // generally it will do this by type and allocate an address for us
    // if we want to do it ourselves, we can with dynamic memory (this is a low-level language feature only)
    int *allocate = new int;
    // the "new" let's us know we just created a new type int



    int i;
    cout << "How many grades will you enter? ";
    cin >> i;

    // this comes into play when we need to define a dynamic length array, so we don't waste space
    int *grades = new int[i];

    // we can capture errorneous values with `new (nothrow) int[i]` to set grades to null if the value is invalid

    // we have to delete allocated variables to free up the memory at the end
    delete allocate;
    // to avoid null pointer reference errors we can now set this to 0
    allocate = 0;

    // do delete grades we have to do this
    delete[] grades;
    // then we have to set a null value to avoid problems referencing after
    grades = 0;

    return 0;
}

