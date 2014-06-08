
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // what will we spit at the file?
    string text = "Bananas";

    // let's create a file stream
    ofstream saveFile;

    // we can open a file
    saveFile.open("saveFile");

    // verify it opened
    if (saveFile.is_open()) {

        // now we can write to it
        saveFile << text << endl;

        // this will overwrite the existing contents

    }

    return 0;
}

