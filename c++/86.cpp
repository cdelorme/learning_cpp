
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main() {

    // we can also use iterators for container classes
    vector<string> v;

    v.push_back("Casey");
    v.push_back("John");
    v.push_back("Jamie");

    // normally we would use a for loop by the size of the item
    // obviously this becomes a problem when we are removing from the array
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }

    // with a map
    map<string, string> m;

    m["Casey"] = "DeLorme";
    m["Jamie"] = "Smith";

    // with a for loop we can no longer use the index on the map to get the current value
    // this is where an iterator allows us to reference each "pair" inside of a map, without using an index or key

    // an iterator is a simple pointer that can be dereferenced
    map<string, string>::iterator i;

    // this is effectively the foreach loop of c++
    for (i = m.begin(); i != m.end(); i++) {
        cout << i->first << " " << i->second << endl;
    }
    // also notice we use -> because we are using a referenced object

    return 0;
}

