
#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main() {

    // multimaps can store multiple values by the same key?
    multimap<string, int> students;

    // we have to use insert /w make_pair
    students.insert(make_pair("casey", 90));
    students.insert(make_pair("john", 80));
    students.insert(make_pair("jamie", 100));
    students.insert(make_pair("casey", 80));

    // it will sort them by name too, neat right?
    multimap<string, int>::iterator i;
    for (i = students.begin(); i != students.end(); i++) {
        cout << i->first << " has a score of " << i->second << endl;
    }

    return 0;
}

