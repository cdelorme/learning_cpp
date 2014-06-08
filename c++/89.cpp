
#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

int main() {

    // lists are another array type
    list<string> names;

    names.push_back("Casey DeLorme");
    names.push_back("Jamie Smith");

    // lists do not support array references (ex. names[0])
    // this is because they are not adjacent in memory, therefore insertion is faster
    // since the pointers just switch where they point to
    // with a vector, to continue adjacent data it has to re-allocate per new addition
    // therefore we have to use an iterator to find values
    list<string>::iterator i;
    for (i = names.begin(); i != names.end(); i++) {
        cout << *i << endl;
        // notice we can use the *i on the iterator, because the iterator is just a pointer
    }

    // with a list, we can use pop_front OR pop_back, allowing us more versatile access
    // we can also add to the rear or the front with `push_front`

    // lists also have a `unique()` method which will kick out duplicates adjacent to eachother
    // we can use sort() beforehand to ensure it removes all duplicates
    // vectors do not have sort or unique

    return 0;
}

