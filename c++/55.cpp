
#include <iostream>

namespace one {
    int x = 10;
    int y = 20;
}
namespace two {
    int x = 20;
    int y = 10;
}

int main() {


    std::cout << one::x << std::endl;


    // we can also create special self-executing scope blocks
    {
        using namespace std;
        using namespace one;
        cout << x << endl;
    }

    {
        using namespace std;
        using namespace two;
        cout << x << endl;
    }

    return 0;
}

