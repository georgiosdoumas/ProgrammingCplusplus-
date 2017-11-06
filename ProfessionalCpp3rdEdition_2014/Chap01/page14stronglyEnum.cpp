// Professional C++ 3rd Ed , Chap 01 page 14 Strongly typed enumerators 
#include <iostream>
using namespace std;
int main()
{
    enum class MyEnum { EnumValue1, EnumValue2 = 10, EnumValue3 };
    enum class charEnum: char { enumchar_d = 'd' , enumchar_f = 'f' }; //I wanted to see if it also compiles, and it does!
    MyEnum variable1 = MyEnum::EnumValue3;
    //cout << variable1 << endl;  //Now this simple way does not compile.
    cout << static_cast<int>(variable1) << " is the value for variable1." << endl;   
    charEnum leter1 = charEnum::enumchar_f ;
    cout << static_cast<char>(leter1) << endl;      
    //As we said on page14a_typedef_enums.cpp, static_cast is mentioned on Chapter10. 
    return 0;
}
// g++ -Wall -std=c++11 -o page14stronglyEnum  page14stronglyEnum.cpp
