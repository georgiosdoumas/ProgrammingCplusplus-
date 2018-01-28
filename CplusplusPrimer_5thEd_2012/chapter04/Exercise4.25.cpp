/* Exercise 4.25: What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit
chars, that uses Latin-1 character set in which ’q’ has the bit pattern 01110001? (which is 113 in decimal) 
*/
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;
int main() 
{
    char ch = 'q';
    unsigned int ich = ch;
    cout << ch << " " << ich << endl;
    cout << ~ch << " " << ~ich << endl;
    cout << ( (~ch) << 6 ) << " " << ( (~ich) << 6 ) << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.25 Exercise4.25.cpp 
// q 113 
// -114 4294967182
// -7296 4294960000

// Because ~01110001 becomes (24bits all 1)10001110 which is not a char anymore but it is a negative integer (4 bytes) 
//In detail:  ~ 00000000 00000000 00000000 01110001  becomes 11111111 11111111 11111111 10001110 
// which if interpreted as signed is (I suppose we have the bitwise-complement implementation of negatives) -114 
// and if interpreted as unsigned, is (I checked it with a calculator in programming mode) 4294967182
// and then shiftin left by 6 positions we get that the 
// 11111111111111111111111110001110  turns into :
// 11111111111111111110001110000000 
// which interpreted as signed is -7296 
// and as unsigned is the number 4294960000 
// Note: in case you have a 64bit laptop/desktop (which is common these days) 
// the above representations will be of 64 bits , so the (~ich)<<6 will be  
// 274877899648 , and not 
// 4294960000 
