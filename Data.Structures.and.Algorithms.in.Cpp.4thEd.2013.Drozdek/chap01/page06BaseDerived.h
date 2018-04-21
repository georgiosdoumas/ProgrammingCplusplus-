#include <iostream>
using std::cout; using std::endl; using std::string;

class BaseClass 
{
  public:
    BaseClass() { }
    void f(string s = "f-unknown");
  protected:
    void g(string s = "g-unknown");
  private:
    void h();
};

class Derived1Level1 : public virtual BaseClass 
{
  public:
    void f(string s = "f-unknown");
    void h(string s = "h-unknown");
};

class Derived2Level1 : public virtual BaseClass 
{
  public:
    void f(string s = "f-unknown");
};

class DerivedLevel2 : public Derived1Level1, public Derived2Level1 
{
  public:
    void f(string s = "f-unknown");
};
