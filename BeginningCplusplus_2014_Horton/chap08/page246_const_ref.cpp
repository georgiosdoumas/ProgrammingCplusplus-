// Beginning C++ 2014 , practicing all the things mentioned on pages 246 and 247
#include <iostream>
long* plarger(long* a, long* b);                     // Pointer parameters
const long* plarger(const long* a, const long* b);   // Pointer to const parameter
long& reflarger(long& a, long& b);
long reflarger(const long& a, const long& b);

int main()
{
    
    long num1 {1L};
    long num2 {2L};
    long num3 {*plarger(&num1, &num2)};      // Calls plarger() that has non-const parameters
    std::cout << num3 << std::endl;
    const long num10 {10L};
    const long num20 {20L};
    const long num30 {*plarger(&num10, &num20)}; // Calls plarger() that has const parameters
    std::cout << num30 << std::endl;
    long num4 { reflarger(num1, num2) };
    std::cout << num4 << std::endl;
    long num5 { reflarger(num10, num20) };
    std::cout << num5 << std::endl;
}
long* plarger(long* pa, long* pb)
{
    std::cout << " long plarger() called" << std::endl;
    return *pa > *pb ? pa : pb;             // returns a pointer-to-Long
}
const long* plarger(const long* pca, const long* pcb)
{
    std::cout << " const-long plarger() called" << std::endl;
    return *pca > *pcb ? pca : pcb;         // returns a pointer-to-constLong 
}
long& reflarger(long& ra, long& rb)
{
    std::cout << " long reflarger() called" << std::endl;
    return ra > rb ? ra : rb;             // returns a reference-to-Long
}
long reflarger(const long& rca, const long& rcb)
{
    std::cout << " const-long reflarger() called" << std::endl;
    return rca > rcb ? rca : rcb;         // returns a reference-to-constLong 
}
//g++ -Wall -std=c++11 -o page246_const_ref page246_const_ref.cpp
/* 
./page246_const_ref
 long plarger() called
2
 const-long plarger() called
20
 long reflarger() called
2
 const-long reflarger() called
20
*/
