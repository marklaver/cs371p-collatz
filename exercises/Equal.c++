// ---------
// Equal.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/equal/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

int main () {
    using namespace std;
    cout << "Equal.c++" << endl;

    {
    const int a[] = {2, 3, 4};
    const int b[] = {2, 3, 4};
    assert(my_equal(a, a + 3, b));
    assert(   equal(a, a + 3, b));
    }

    cout << "Done." << endl;
    return 0;}
