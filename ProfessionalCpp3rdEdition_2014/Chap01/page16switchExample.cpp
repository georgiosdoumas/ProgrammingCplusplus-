// Professional C++ 3rd Ed , Chap 01 page 16 example on switch, taking the opportunity to try enums again!
#include <iostream>
using namespace::std;

int main()
{
    enum class color_codes: char { red = 'R' , green = 'G' , blue = 'B' };
    color_codes background1 = color_codes::green;  //definition and initialization of an enumerated variable
    //color_codes background2 = color_codes::wrongcolor;  //non existent color, it does not compile
    //color_codes background2 = 'B';   //does not compile either, we have to use static_cast:
    color_codes background2 = static_cast<color_codes>('B');
    color_codes background3 = static_cast<color_codes>('W'); //  Unrecognized color!
    switch (background1) {
        case color_codes::red: cout << 'R' << endl;
                  break;
        case color_codes::green: cout << 'G' << endl;
                  break;
        //case 'B' : cout << 'B' << endl;  //compile error!
        case color_codes::blue: cout << 'B' << endl;
                  break;
        default: cout << "Unrecognized color! " << endl;
      }
    switch (background2) {
        case color_codes::red: cout << 'R' << endl; break;
        case color_codes::green: cout << 'G' << endl; break;
        case color_codes::blue: cout << 'B' << endl; break;
        default: cout << "Unrecognized color! " << endl;
      }
    switch (background3) {
        case color_codes::red: cout << 'R' << endl; break;
        case color_codes::green: cout << 'G' << endl; break;
        case color_codes::blue: cout << 'B' << endl; break;
        default: cout << "Unrecognized color! " << endl;
      }
    return 0;
}
// g++ -Wall -std=c++11 -o page16switchExample page16switchExample.cpp
// ./page16switchExample
