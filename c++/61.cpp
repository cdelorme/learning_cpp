
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // let's read with getline!
    ifstream saveFile("1.cpp");

    // verify it opened
    if (saveFile.is_open()) {

        // loop all lines fully
        while (!saveFile.eof()) {

            string tempString;
            getline(saveFile, tempString);
            // getline also lets us specify a delimeter as the third argument, for example comma delineated
            cout << tempString << endl;
            // now we get the entire file with all spaces
        }

    }

    saveFile.close();

    return 0;
}

