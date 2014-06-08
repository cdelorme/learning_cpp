
#include <iostream>

using namespace std;

int main() {

    // acquire grade
    bool done = false;
    float total = 0;
    int amount;

    while (!done) {

        cout << "Enter the amount of numbers: ";
        cin >> amount;

        for (int i = 0; i < amount; i++) {

            char op;
            float number;

            cout << "Enter the operator (" << total << ") ";
            cin >> op;
            cout << "Enter a number: ";
            cin >> number;

            switch (op) {
                case '+':
                    total += number;
                    break;
                case '-':
                    total -= number;
                    break;
                case '/':
                    total /= number;
                    break;
                case '*':
                    total *= number;
                    break;
            }

        }

        cout << "Total: " << total << endl;

        // ask if they want to do another
        cout << "Do you want to run again? (y|n)" << endl;
        cin.clear();
        cin.ignore();
        if (cin.get() != 'y') {
            done = true;
        }

    }

    return 0;
}

