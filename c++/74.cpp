
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // vectors are the most awesome tool
    // they are arrays of variable length
    // they very likely use templates, fortunately I don't have to write the code!

    // we create them and define the data type they store
    vector<int> numbers;

    // using some vector functions
    // this will insert a new int
    numbers.push_back(20);

    // we can access it easily just like an array
    cout << numbers[0] << endl;

    // you can see and modify then by index now too
    numbers[0] = 15;

    // similarly you can use at()
    cout << numbers.at(0) << endl;

    // we can also pop out data
    numbers.pop_back();

    return 0;
}

