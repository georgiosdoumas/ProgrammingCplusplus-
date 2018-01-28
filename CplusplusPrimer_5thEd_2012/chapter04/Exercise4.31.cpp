/* Exercise 4.31: The program in this section used the prefix increment and decrement
operators. Explain why we used prefix and not postfix. What changes would have to
be made to use the postfix versions? Rewrite the program using postfix operators. */
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
int main() 
{
    //size_t size;
    vector<int>::size_type size ;
    cout << "Give me the size of the integer vector : " ;
    cin >> size;
    vector<int> ivec(size,0); 
    vector<int>::size_type cnt = ivec.size();
    cout << "Constructing a descending vector, according to given size ... " << endl;
        // assign values from size . . . 1 to the elements in ivec
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        { ivec[ix] = cnt; cout << "assigned " << cnt << " to ivec[" << ix << "] " << endl; } 
    for (auto vel : ivec) cout << vel << " " ;
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.31 Exercise4.31.cpp 
// So I did not have to change anything on the rest of the program , when using ix++ , cnt-- instead of ++ix,--cnt
//No need to change the boundaries or anything else. I do not know what Lippman expected from this exercise. 
