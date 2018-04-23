#include <iostream>
#include <cmath>
using namespace std;

double rootfind(double (*f)(double), double a, double b, double epsilon) 
{
    double middle = (a + b) / 2; //initial guess for the point that function will give value of 0 
    while (f(middle) != 0 && fabs(b - a) > epsilon) //it does not have to be strictly 0, we are happy if it is < epsilon
    {
        if (f(a) * f(middle) < 0)   // if f(a) and f(middle) have opposite signs, so the function was 0 for some x 
               b = middle;   //...then your new section (a,b) to search for f(x)=0 is between a and middle 
        else if (f(middle) * f(b) < 0)  
               a = middle;    //else search in the (middle, b) section
        else { cout << " No root inside section ("<<a<<","<<b<<") give a better section" << endl; return middle; }
        middle = (a + b) / 2;   //make a new initial guess for where the f(middle)=0
        cout << "\t Current guess: " << middle << endl;
    }
    return middle;
}

double cubicx(double x) { return (x*x*x + 4) ;}
double curvex(double x) { return (x*x -16); }

int main()
{
	
	double root1, root2;
	root1 = rootfind(cubicx, -10.0, 8.0, 0.0001);
	root2 = rootfind(curvex, -2, 12, 0.0001);
	cout << root1 << " , " << root2 << endl;
}

// /usr/bin/g++ -Wall -std=c++11 -o page21_roots page21find_roots.cpp
