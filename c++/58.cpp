
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // a file stream object
    ifstream saveFile;
    // if and of streams, also fstream to do both read and write

    // we can grap my first file
    saveFile.open("1.cpp");

    // we can also do it in oneline via
    // ifstream saveFile("1.cpp");

    // ideally you should wrap the open process in a try catch in case of failure

    // another builtin is:
    if (saveFile.is_open()) {

        // now we know it worked and we can read it

        cout << "Reading file 1.cpp" << endl;

        // we can iterate with a while
        while (!saveFile.eof()) {
            string tempString;
            // we can use the same approach as with cin
            saveFile >> tempString;
            // this will ignore contents after spaces, and spaces before contents
            // this is a problem if you want the actual formatting of the file contents
            cout << tempString << endl;
        }
    }

    return 0;
}

