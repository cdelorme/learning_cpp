
#include <iostream>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

int main() {

    unordered_map<string, float> students;

    // also unordered_multimap exists

    students.insert(make_pair("casey", 4.0));
    students.insert(make_pair("john", 3.8));

    unordered_map<string, float>::iterator i;
    for (i = students.begin(); i != students.end(); i++) {
        cout << i->first << " has a gpa of " << i->second << endl;
    }

    // as with unordered_set, different sorting and recall algorithm with c++ 11

    return 0;
}

