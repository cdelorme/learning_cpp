
#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include <typeinfo>

using namespace std;

int main() {

    // how auto is amazing?  Iterators...
    map<string, float> student;

    student["casey"] = 4.0;
    student["john"] = 3.8;

    // the old way:
    //map<string, float>::iterator i;
    // it's tedious, so instead why not:
    // what if we have many maps?

    // super shorthand solution woohoo!
    for (auto i = student.begin(); i != student.end(); i++) {
        cout << i->first << " has a gpa of " << i->second << endl;
    }

    return 0;
}

