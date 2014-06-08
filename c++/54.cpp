
#include <iostream>

using namespace std;

namespace one {
    int x = 10;
    int y = 20;
}
namespace two {
    int x = 20;
    int y = 10;
}

using namespace one;
using namespace two;

int main() {

    // now we have lots of overlapping variables
    // something like this will fail:
    //cout << x << endl;

    // the best practice is to use the namespace with the unary operator
    cout << one::x << endl;

    return 0;
}

