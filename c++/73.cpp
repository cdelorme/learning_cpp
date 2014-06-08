
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // we can also compare without using ==
    string one = "One";
    string two = "Two";
    string three = "One";

    cout << one.compare(two) << endl;
    cout << one.compare(three) << endl;

    // it gives us a queer output though?

    return 0;
}

