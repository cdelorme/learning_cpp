
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // we can also create multi-dimensional vectors by wrapping them as a type
    vector< vector<int> > numbers;
    // the spaces here are important, you cannot have >> together!

    // for each new row we can add a new vector of integers
    numbers.push_back(vector<int>());

    // now we can set a value
    numbers[0].push_back(25);

    // finally we can access it using double array indexes
    cout << numbers[0][0] << endl;

    // or with the method chain of at()
    cout << numbers.at(0).at(0) << endl;

    return 0;
}

