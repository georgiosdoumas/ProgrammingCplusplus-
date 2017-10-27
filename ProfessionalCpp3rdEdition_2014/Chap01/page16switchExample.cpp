// Professional C++ 3rd Ed , Chap 01 page 16 example on switch, taking the opportunity to try enums again!
#include <iostream>
using namespace::std;
int main()
{
    enum class color_codes: char { red = 'R' , green = 'G' , blue = 'B' };
    color_codes background = color_codes::green;  //definition and initialization of an enumerated variable
    switch (background) {
        case color_codes::red: cout << 'R' << endl;
                  break;
        case color_codes::green: cout << 'G' << endl;
                  break;
        //case 'B' : cout << 'B' << endl;  //compile error! 
        case color_codes::blue: cout << 'B' << endl;
                  break;
        default: cout << "Unrecognized color! " << endl;
    }
    return 0;
}
// g++ -Wall -std=c++11 -o page16switchExample page16switchExample.cpp
// ./page16switchExample
