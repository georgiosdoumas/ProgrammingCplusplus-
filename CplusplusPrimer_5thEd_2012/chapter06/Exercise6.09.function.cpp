/* Exercise 6.9: Write your own versions of the fact.cc and factMain.cc files. These
files should include your Chapter6.h from the exercises in the previous section. Use
these files to understand how your compiler supports separate compilation. */
// Actually I chose to use Exercise6.7 and seperate it in different files , doing also some modifications
// that is : I create a static vector 

#include "Exercise6.09function.h"

size_t count_calls()
{
    static size_t ctr = 0;
    static vector<int> vint ;
    if (ctr != 0 ) vint.push_back(ctr) ;
    for (auto j : vint ) cout << j << "-" ;
    cout << endl;
    return ctr++;
}
