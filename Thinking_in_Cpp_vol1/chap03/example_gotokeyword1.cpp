//: C03:gotoKeyword.cpp
// The infamous goto is supported in C++
// but here is one alternative solution that I made.
#include <iostream>
using namespace std;
int main() 
{
  long val = 0;
  for(int i = 1; i < 1000; i++) 
  {
    cout << "i="<<i<<endl;
    for(int j = 1; j < 100; j += 10) 
    {
      val = i * j;
      cout<<"  j="<<j;
      if(val > 47000)  
         { cout << "\nval=" << val << endl; return 0; }  
    }
    cout<<endl;
  }
} 
