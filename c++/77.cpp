
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    vector<int> numbers;
    numbers.reserve(4);

    // we can however check capacity to see reserved space
    cout << numbers.capacity() << endl;

    // this may be useful later when comparing size to capacity to determine whether to resize the vector to its contents

    return 0;
}

