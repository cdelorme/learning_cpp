
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // searching contents in files

    // ifstream has ios::in by default, and any extras add onto that option
    // same with ofstream but reversed, and fstream will actually replace not add to options, but comes with ios::in and ios::out together
    // ios::app only works for ofstream, and will always write to the end of the file regardless of seek position
    // ate will start the pointer at the end of the file but can be moved and writing will be merged in between contents
    fstream saveFile("saveFile");

    if (saveFile.is_open()) {

        // seekp for output stream, seekg for input stream, these are separate pointers

        // we can seek to different positions
        saveFile.seekp(10);

        // this will replace a character at position 8
        saveFile.put('y');

        // this will go backwards to position 5
        saveFile.seekp(5);

        // this will be inserted same as <<, it will not overwrite the content*!
        saveFile.write("whee", strlen("whee"));

        // close our file always
        saveFile.close();
    }

    return 0;
}

