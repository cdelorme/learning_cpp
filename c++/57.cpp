
#include <iostream>

using namespace std;

int main() {

    int num1 = 2, num2 = 0;

    // we can catch errors with try/catch
    try {
        if (num2 == 0) {
            // we can force exceptions with throw
            throw 20;
        }
    } catch (int x) {
        cout << "Failed" << endl;
    }

    return 0;
}

