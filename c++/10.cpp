
#include <iostream>

using namespace std;

int main() {

    // acquire grade
    int grade;
    char letter;

    // loop to get grade
    int count = 0;
    do {

        cin >> grade;
        // check grade to spit back letter
        if (grade > 80) {
            letter = 'A';
        } else if (grade > 70) {
            letter = 'B';
        } else if (grade > 60) {
            letter = 'C';
        } else if (grade > 50) {
            letter = 'D';
        } else {
            letter = 'F';
        }

        cout << letter << endl;

        count++;
    } while (count < 10);

    return 0;
}

