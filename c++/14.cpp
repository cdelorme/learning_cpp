
#include <iostream>

using namespace std;

int main() {

    int numStudents = 15;
    int students[numStudents];

    for (int i = 0; i < numStudents; i++) {

        cout << "Enter grade for student " << i + 1 << ": ";
        cin >> students[i];
        cout << endl;

    }


    return 0;
}

