
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // initialize random so we don't get the same value from rand over and over
    srand(time(0));

    // create 10 sets with asterisks to represent count
    for (int i = 0; i < 10; i++) {
        int randNum = rand() % 15; // 0-14, add +1 to start at 1
        for (int j = 0; j < randNum; j++) {
            cout << '*';
        }
        cout << endl;
    }

    // if you wanted to calculate damage for example, with a min & max damage based on weapon and character str and enemy def
    // you could use the above % (max - min) + min

    return 0;
}

