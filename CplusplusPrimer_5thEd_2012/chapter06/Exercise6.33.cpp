/* Exercise 6.33: Write a recursive function to print the contents of a vector. */
#include <iostream>
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
//A first attempt , but it prints from last-to-first elements! 
void reverse_print (const vector<int> &intvec, vector<int>::size_type finish)
{  
	if (finish != 0 ) 
	{
	    cout << intvec[finish-1] << "-";
	    reverse_print(intvec, finish - 1);  //call again the function on a shrinking vector
	}
}
//A correct solution , using iterators and having an always-new-beginning :
void print_intvect(const vector<int> &iv ,vector<int>::iterator viterbeg)
{
    if( viterbeg < iv.end() )           //are we still not at the end? 
    {
      cout << *(viterbeg++) << "-" ;   //print current position's element, and move the iterator to next element ...
      print_intvect(iv , viterbeg) ; //...and call again the function (that will print the forwarded iteretor,and call again...)
    }
}

int main()
{
	vector<int> ivec {1,2,3,4,5,6,7,8,9};
	auto szivec = ivec.size();     // vector<int>::size_type szivec = ivec.size();  //the elaborate way to do it
	reverse_print(ivec,szivec);
	cout << endl;
    vector<int> iv{11};
    int sziv = iv.size();
    reverse_print(iv, sziv);
    cout << endl;
    auto beg = ivec.begin();
    print_intvect(ivec, beg);
    cout << endl;
    return 0;
}
// g++ -Wall -std=c++11 -o Exercise6.33 Exercise6.33.cpp 
