
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    fstream saveFile("saveFile");

    if (saveFile.is_open()) {

        string find = "Banana";
        int index = 0;

        while (!saveFile.eof() || index > 0) {

            // find index of find string
            // not going to for now, too much work

        }
    }

    return 0;
}

