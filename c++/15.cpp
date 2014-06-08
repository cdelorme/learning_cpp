
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // begin random
    srand(time(0));

    // generate 15 students
    int numStudents = 15;
    int students[numStudents];
    char letter;

    // generate random grades
    for (int i = 0; i < numStudents; i++) {

        // generate grade
        students[i] = rand() % 100 + 1;

        // print letter grade
        if (students[i] > 80) {
            letter = 'A';
        } else if (students[i] > 70) {
            letter = 'B';
        } else if (students[i] > 60) {
            letter = 'C';
        } else if (students[i] > 50) {
            letter = 'D';
        } else {
            letter = 'F';
        }

        cout << "Letter Grade for student " << i + 1 << " : " << letter << endl;

    }

    return 0;
}

