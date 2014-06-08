
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // you can set the number of values, and the defaults with the constructor
    vector<int> numbers(4, 100);

    // you can also copy an entire vector with the same constructor
    vector<int> numbersTwo(numbers);

    cout << numbersTwo[1] << endl;

    // we can also get the size of a vector array with size
    cout << numbers.size() << endl;

    return 0;
}

