#include <iostream>
using std::cout; using std::endl;

class	complex
{
	public: 
	  complex(double rval, double ival) : r{rval}, i{ival} { } 
	  complex(double rval) : r{rval} {std::cout << "1st delegated, one-arg, ctor was used!\n";}
	  complex() { std::cout << "2nd delegated no-args ctor was used!\n";}  //complex():complex(0.0) {} also compiles and gives same result
	  
	  complex(const complex& c) : r(c.r), i(c.i)  // copy constructor. For this simple class, we could skip it
	    { std::cout << "Copy constructor was called!\n"; }  
	  
	  
	  const double& m_real() const 
	    { return r; } // if a maintainer in the future would try to do something stupid, like {return ++r;}, due to const keywords
	                  // the compiler will issue an error. So we protect the implementation 
	  //double& m_imag() { return i; }   // I decided to implement the imag with a friend function, just to show how it is done
	  
	  friend double& imag(complex& c) ;  
	  friend const double& imag(const complex& cc) ;  
	  
	private:    
	  double r=1.0, i=0.0;
};

inline const double& real(complex& c) { return c.m_real(); }
inline const double& real(const complex& c) { return c.m_real(); } // this is required for the cc1 in main()

// for the next function definition, remember: no keyword friend is needed outside of the class declaration!
double& imag(complex& c) { return c.i; }  // no need to use the m_imag() , since as friend can access directly the member i
const double& imag(const complex& cc) { return cc.i; }    // this is required for the cc1 in main()


int main()
{
	complex c1;
	cout << "(" << real(c1) << ", " << imag(c1) << ")" << endl;
	const complex cc1(3.2, 5.9);
	cout << "(" << real(cc1) << ", " << imag(cc1) << ")" << endl;
}

// g++ -Wall -Wextra -std=c++11 2.6.1referencesToTemporary.cpp -o 2.6.1referencesToTemporary
