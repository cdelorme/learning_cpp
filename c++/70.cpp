
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // support for utf8 is important!
    string test = "ヘッロせかい";
    cout << test << endl;

    // we can find the index of a word by using find
    cout << test.find("せ") << endl;
    // there are many caveats, noticing the index of a utf8 character takes 3 bytes per
    // also find with multiple characters will treat each individually not as a single string
    // there are many other find functions as well

    // we can also erase contents from a string
    // notice how incredibly odd it treats special characters as 3 characters in length?
    test.erase(test.find("せ"));
    cout << test << endl;

    return 0;
}

