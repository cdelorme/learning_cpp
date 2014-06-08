
#include <iostream>

using namespace std;

int main() {
    // define them and demo data loss
    double t1 = 12.2;
    float t2 = t1;
    int t3 = t2;
    bool t4 = true;
    char t5 = 'l';

    // by default these are signed

    // print them
    cout << t1;
    cout << endl;
    cout << t2;
    cout << endl;
    cout << t3;
    cout << endl;
    cout << t4;
    cout << endl;
    cout << t5;
    return 0;
}

