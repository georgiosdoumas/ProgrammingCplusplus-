//: C03:gotoKeyword.cpp
// The infamous goto is supported in C++
//but here is another alternative solution.
//I used the advice mentioned in the book, http://www.drbio.cornell.edu/pl47/programming/TICPP-2nd-ed-Vol-one-html/Frames.html
//but it is not well expressed.
//It says in the text 
//"The alternative would be to set a Boolean that is tested in the outer for loop, and then do a break from the inner for loop."
//but in reality it should say :
//The alternative would be to set a Boolean that is tested in the inner for loop, and then do a break from the outer for loop.
//I cannot believe that after 15 years and so many eyes reading the text , it has still remained uncorrected.

#include <iostream>
using namespace std;
int main() 
{
  long val = 0;
  for(int i = 1; i < 1000; i++) 
  {
    bool is47000 = false;
    cout << "i="<<i<<endl;
    for(int j = 1; j < 100; j += 10) 
    {
      val = i * j;
      cout<<"  j="<<j;
      if(val > 47000)  is47000 = true; //we reached the value we want
    }
    cout<<endl;
    if(is47000==true) break; //exit loop and print val
  }
  cout << "\nval=" << val << endl;
} 
