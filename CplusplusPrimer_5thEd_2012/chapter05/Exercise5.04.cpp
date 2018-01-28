/* Exercise 5.4: Explain each of the following examples, and correct any problems you
detect.
(a) while (string::iterator iter != s.end()) { //do stuff   }
(b) while (bool status = find(word)) {// do something   }
    if (!status) { // do stuff in case status is false, which means that !status is true  }   
*/
//a) is wrong because we have not initialized the iterator
//  It should be for example :
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;
bool find( string word2search) { return false;}  // defining the function in a very simple way, just to avoid an endless loop.
int main() 
{
    string s = "Test string.";
    string word {"simple"};
    string::iterator iter = s.begin();
    while ( iter!=s.end() ) { 
    	cout << *iter << " ";
    	++iter;
    }
  // b) is also wrong because status is not visible outside the scope of {//do something } 
    bool status {true};
    // the find(something) should be a function that returns a boolean value  
    while ( (status = find(word)) ) {/* do something, as long as you keep finding word */  }
    // After you exit the while loop, most probably status will be false (but a break may have exited the loop earlier)
    if (!status) { cout << "false!" << endl; }
    return 0;
}
// g++ -Wall -std=c++11 -o Exercise5.4 Exercise5.04.cpp 

