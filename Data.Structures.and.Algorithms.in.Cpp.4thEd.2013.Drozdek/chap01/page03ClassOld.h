#include <cstring>
#include <iostream>
using std::cout; using std::endl;

class C_old 
{
  public:
    C_old(char *s = "", int i = 0, double d = 1);
    void memberFunction1(); 
    void memberFunction2(int i, const char *s = "unknown"); 
	
  private:
    char dataMember1[20];
    int dataMember2;
    double dataMember3;
};
