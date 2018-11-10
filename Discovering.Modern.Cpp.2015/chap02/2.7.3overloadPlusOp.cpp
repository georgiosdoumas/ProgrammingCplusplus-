// Overloading the + and - operators with various ways 
#include <iostream>

class	complex
{
  public:
    explicit complex(double rn= 0.0, double in= 0.0) : r(rn), i(in) { }
    
    friend inline double& real(complex& c) { return c.r; }  // { return c.real(); } ??  
    friend inline const double& real(const complex& c) { return c.r; }  
    friend inline double& imag(complex& c) { return c.i; }
    friend inline const double& imag(const complex& c) { return c.i; }
      
    complex operator+(const complex& c2) const
    { return complex(r + c2.r, i + c2.i); }
    
    complex operator+(double r2) const
    { return complex(r + r2, i ); }
    
    friend inline complex operator-(const complex& c1, const complex& c2);
    friend inline complex operator-(double d, const complex& c2);
    friend inline complex operator-(const complex& c1, double d);
   
     
    friend std::ostream& operator<<(std::ostream& someOutStream, const complex& c); 
    
  private:
    double r, i;
};

complex operator-(const complex& c1, const complex& c2)
{ return complex(real(c1) - real(c2) , imag(c1) - imag(c2) ); }

complex operator-(double d, const complex& c2)
{ return complex( d-real(c2) , imag(c2) );}

complex operator-(const complex& c1, double d)
{ return complex( real(c1) - d , imag(c1) ); }

std::ostream& operator<<(std::ostream& someOutStream, const complex& c)
{ return someOutStream << '(' << real(c) << ',' << imag(c) << ')'; }  // or more elaborate : 
//{ someOutStream << '(' << real(c) << ',' << imag(c) << ')'; return someOutStream; }
    
int	main()
{
  complex z0;
  std::cout << "z0 is " << z0 << std::endl;
  const complex cz( -1, -3 );
  std::cout << "constant cz is " << cz << std::endl;
  complex cc(7.0,	8.0), c4(cc);
  std::cout << "cc  is " << cc << std::endl;	
  std::cout << "cc + c4 is " << cc + c4 << std::endl;	
  std::cout << "cc + 3.5 is " << cc + 3.5 << std::endl;
  std::cout << "cc - c4 is " << cc - c4 << std::endl;
  std::cout << "cz - cc is " << cz - cc << std::endl;
  std::cout << "cz - 2.1 is " << cz - 2.1 << std::endl;
  std::cout << "2.3 - cz is " << 2.3 - cz << std::endl;
  complex sum = cc + c4;  // for now, no need for operator=(...)
  std::cout << "Sum cc + c4 is " << sum << std::endl;
}

// g++ -Wall -Wextra -std=c++11 2.7.3overloadPlusOp.cpp -o 2.7.3overloadPlusOp
