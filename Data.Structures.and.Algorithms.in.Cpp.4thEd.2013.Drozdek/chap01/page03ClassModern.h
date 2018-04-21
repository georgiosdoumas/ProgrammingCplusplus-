//#include <string>  not actually needed, since we do not use any functions of string class in this program
#include <iostream>
using std::cout; using std::endl;
using std::string;

class C_Modern 
{
  public:
    C_Modern(string s = "", int i = 0, double d = 1);
    void memberFunction1() const; 
    void memberFunction2(int i, string s = "unknown"); 
	
  private:
    string dataMember1;
    int dataMember2;
    double dataMember3;
};
