
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // begin random
    srand(time(0));

    // generate 15 students
    int numStudents = 15;
    int numTests = 4;
    int students[numStudents][numTests];
    char letter;

    // generate random grades
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numTests; j++) {

            // generate grade
            students[i][j] = rand() % 100 + 1;

            // print letter grade
            if (students[i][j] > 80) {
                letter = 'A';
            } else if (students[i][j] > 70) {
                letter = 'B';
            } else if (students[i][j] > 60) {
                letter = 'C';
            } else if (students[i][j] > 50) {
                letter = 'D';
            } else {
                letter = 'F';
            }

            cout << "Letter Grade on test " << j + 1 << " for student " << i + 1 << " : " << letter << endl;
        }
    }

    return 0;
}

