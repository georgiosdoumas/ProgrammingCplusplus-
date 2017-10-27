// Professional C++ 3rd Ed , Chap 01 page 14 Strongly typed enumerators 
#include <iostream>
using namespace std;
int main()
{
    enum class MyEnum { EnumValue1, EnumValue2 = 10, EnumValue3 };
    enum class charEnum: char { enumchar_d = 'd' , enumchar_f = 'f' }; //I wanted to see if it also compiles, and it does!
    MyEnum variable1 = MyEnum::EnumValue3;
    //cout << variable1 << endl;   //compiler error
    charEnum leter1 = charEnum::enumchar_f ;
    //cout << leter1 << endl;      //compiler error
    //So we do not know yet how to print the values of these enumerators (but see page16switchExample.cpp )
    return 0;
}
// g++ -Wall -std=c++11 -o page14stronglyEnum  page14stronglyEnum.cpp
