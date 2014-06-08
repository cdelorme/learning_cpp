
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string text = "saving...";

    // this time we will specify we want to append to the file
    ofstream saveFile("saveFile", std::ofstream::app);

    // verify it opened
    if (saveFile.is_open()) {

        // this time when we write it will add it to the end of the file
        saveFile << text << endl;

    }


    // you should always close your file when done
    saveFile.close();

    return 0;
}

