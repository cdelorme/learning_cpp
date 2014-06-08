
#include <iostream>
#include <string>
#include <iterator>
#include <set>

using namespace std;

int main() {

    // set container
    set<string> names;

    names.insert("Casey DeLorme");
    names.insert("Jamie Smith");

    // these are like an array, except they allow the data type as the key
    cout << names["Casey DeLorme"] << endl;

    // this is useful if you need an array of items that you lookup by themseves
    // for example if every instance of an object should be unique you can find an instance in a set
    // so for simple lookups without looping the set object

    return 0;
}

