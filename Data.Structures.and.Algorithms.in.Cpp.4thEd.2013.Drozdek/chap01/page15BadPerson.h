#include <cstring>
using namespace std;
class badPerson
{
  public:
    char *pname;
    int age;
    badPerson(char *n = "", int a = 0) //a constructor with 2 default parameter values
    {
  	    pname = strdup(n);
	    age = a;
    }
};

class goodPerson
{
  public:
    char *pname;
    int age;
    goodPerson(char *n = "", int a = 0) //a constructor with 2 default parameter values
    {
  	    pname = strdup(n);
	    age = a;
    }
    goodPerson(const goodPerson& n) 	// copy constructor, for an example of assignment constructor see page16ModernPerson.h
    { 
         pname = strdup(n.pname);
         age = n.age;
    }
};
