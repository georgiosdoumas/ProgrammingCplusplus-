#include <string>
#include <iostream>
using namespace std;

class modernPerson
{
  private:   //of course it would be simpler to declare: string name;
    string* pname = nullptr;  //...We are only doing this with pointer, to present the need for copy constructor
    int age;						
  public:
    modernPerson(string nm = "NONAME", int a = 1) //a constructor with 2 default parameter values
    {
  	    pname = new string{nm};
	    age = a;
    }
    ~modernPerson()  		// destructor for the dynamically allocated pname
    { 
       cout << " Destroying " << *pname << " at position " << pname <<"!" << endl; 
       if (pname != nullptr) delete pname; 
    }
    string& getname() const { return *pname;}
    int getage() const { return age;}
    void setname(const string& nm ) { *pname = nm; }
    void setage(int ag) { age = ag; }
    modernPerson(const modernPerson& mp) 	// copy constructor
    { 
    		pname = new string;
         *pname = *(mp.pname);
         age = mp.age;
    }
    modernPerson& operator=(const modernPerson& mp) // assignment operator 
    {
	if (this != &mp) // no assignment to itself;
	{ 
	   if (pname != nullptr)
	         { delete pname; pname = nullptr; }
	     pname = new string;
             *pname = *(mp.pname);
	     age = mp.age;
	 }
	 return *this;
    }    
};

ostream& operator<<(ostream& outstrm, const modernPerson& mp)
{
	outstrm << mp.getname() << ' ' << mp.getage() << endl;
	return outstrm;
}
