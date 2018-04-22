#include <iostream>
using namespace std;

int main()
{
	int a[5], *p;
	//a = p; //wrong
	//a++;    //wrong
	for ( int i = 0; i < 5; i++) 
	  a[i] = 2*i;
	int sum1,i;
	for (sum1 = a[0], i = 1; i < 5; i++)
        sum1 += a[i];
   cout << sum1 << endl;
   int sum2;
   for (sum2 = *a, p = a+1; p < a+5; p++)
        sum2 += *p;
   cout << sum2 << endl;
   int n = 10;
  
	p = new int[n];
	for ( int i=0 ; i < n; ++i)
	  p[i] = 3*i + 10;
	int sum3;
	for (sum3 = *p, i = 1; i < n; i++)  //for (sum = p[0], i = 1; i < n; i++)   sum3 += p[i];
	  sum3 += *(p+i);
   cout << sum3 << endl;  
   delete [] p; 
   p = nullptr; 
}

// /usr/bin/g++ -Wall -std=c++11 -o page13 page13main.cpp
