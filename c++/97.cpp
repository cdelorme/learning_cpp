
#include <iostream>
#include <string>
#include <iterator>
#include <typeinfo>

using namespace std;

int main() {

    int v = 5;
    auto v2 = 4;

    // auto is a keyword that checks a type at time of creation
    // this is amazingly flexible
    // it will give you some trouble with warnings because it is a newer c++ 11 extension

    cout << v2 << endl;


    // typeid also lets us identify the type of a variable
    cout << typeid(v).name() << endl;

    return 0;
}

