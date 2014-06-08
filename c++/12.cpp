
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // initialize random so we don't get the same value from rand over and over
    srand(time(0));

    // display random number
    int r = rand();
    cout << r << endl;

    // we can use modulus to limit range
    cout << r % 15 << endl;

    return 0;
}

