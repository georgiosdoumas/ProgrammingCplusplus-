/* Exercise 4.20: Assuming that iter is a vector<string>::iterator, indicate
which, if any, of the following expressions are legal. Explain the behavior of the le-
gal expressions and why those that aren’t legal are in error.
(a) *iter++;
(b) (*iter)++;
(c) *iter.empty()
(d) iter->empty();
(e) ++*iter;
(f) iter++->empty();
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
    vector<string> text;
    vector<string>::iterator striter = text.begin();
    *striter++;   //equivalent to *(striter++) ;  OK , an iterator can be advanced with ++ 
    //(*striter)++;  // a string does not have the ++ operator defined ! 
    //*striter.empty() ; //Equivalent to *(striter.empty() ) which is wrong,a pointer to string has no empty() member.   
    striter->empty() ;  // or (*striter).empty(); 
    //++*striter;    //no ++prefix operator exists for a string ! 
    striter++->empty(); // equivalent to (striter++)->empty();
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise4.20 Exercise4.20.cpp 
