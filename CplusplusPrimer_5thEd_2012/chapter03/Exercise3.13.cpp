/* Exercise 3.13: How many elements are there in each of the following vectors? What
are the values of the elements?
(a) vector<int> v1;         // zero elements
(b) vector<int> v2(10);     // 10 integer elements , default initialized to 0
(c) vector<int> v3(10, 42); // 10 ints : all of them have value  42  
(d) vector<int> v4{10};     // 1 int : value 10
(e) vector<int> v5{10, 42}; // 2 ints : 10 and 42 
(f) vector<string> v6{10};  // 10 empty (default initialized) strings
(g) vector<string> v7{10, "hi"}; // 10 strings , all of them are "hi" , but prefer to write it as: v7(10, "hi");
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    vector<int> v2(10);
    cout << v2[3] << endl;  // 0
    vector<int> v3(10, 42);
    cout << v3[9] << endl;  //42 
    cout << v3[10] << endl;  // out of limits , compiler accepts it but outputs a garbage value. DANGEROUS! 
    vector<int> v4{10}; 
    cout << v4[0] << endl;  //10
    vector<int> v5{10, 42};
    cout << v5[0] << " " << v5[1] << endl;  //10 42 
    vector<string> v6{10};
    cout << v6[4] << endl;   // empty string 
    vector<string> v7{10, "hi"}; 
    cout << v7[9] << endl;
    vector<string> v8(4, "hello"); // 4 strings , all have value "hello". This is the natural way of writing case (g) for v7 
    cout << v8[3] << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.13 Exercise3.13.cpp 
