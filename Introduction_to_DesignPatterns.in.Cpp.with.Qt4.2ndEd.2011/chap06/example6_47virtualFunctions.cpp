#include <iostream>

class Base 
{
public:
    Base() { ++sm_bases; }
    virtual ~Base() { --sm_bases; }  // the book neglects the virtual keyword here, which is bad. I suppose the book wants us to realize it.
    void a();
    virtual void b();
protected:
    static int sm_bases;
};

class Derived : public Base 
{
public:
    Derived() { ++sm_deriveds; }
    ~Derived() { --sm_deriveds; }
    void a();
    void b();
    static void showCounts() {
        std::cout << "Bases:" << sm_bases << " Deriveds:" << sm_deriveds << std::endl;
    }
protected:
    static int sm_deriveds;
};
// for simplicity I do not have a seperate .hpp and .cpp file 
int Base::sm_bases(0);
int Derived::sm_deriveds(0);
void Base::a() { std::cout << "Base::a()\n" ;}
void Base::b() { std::cout << "Base::b()\n" ;}
void Derived::a() { std::cout << "Derived::a()\n" ;}
void Derived::b() { std::cout << "Derived::b()\n" ;}


void foo() 
{
    Derived d1;
    Base b1;
    Base* bp = new Derived();
    bp->a();  // calls Base::a() since the pointer bp was declared as having a type of Base* AND a() is NOT a virtual function (so a static binding happens).
    bp->b();  // calls Derived::b() because b() is a virtual function so since bp is actually a Derived object, the dynamic binding will happen
    delete bp;
    Derived::showCounts();
    std::cout << "  Exiting foo(), so 1 local object will be destroyed!" << std::endl;
}

//for simplicity I do not have another file for main.cpp
int main() 
{
    Base b;
    Derived d;
    std::cout << "Before entering foo(): " ;
    d.showCounts();
    foo();
    std::cout << "After calling foo(): " << std::endl;
    //d.showCounts();// or equivalently, since showCounts() is a static function, so we do not need an instantiated object to call it, we can use the class name:
    Derived::showCounts();  
    
}

/* 
Before entering foo(): Bases:2 Deriveds:1
Base::a()
Derived::b()
Bases:4 Deriveds:2
  Exiting foo(), so 1 local object will be destroyed!
After calling foo(): 
Bases:2 Deriveds:1

   //If we neglect the virtual for the destructor of the Base, here is the output with the wrong numbers: 
Before entering foo(): Bases:2 Deriveds:1
Base::a()
Derived::b()
Bases:4 Deriveds:3
  Exiting foo(), so 1 local object will be destroyed!
After calling foo(): 
Bases:2 Deriveds:2
*/ 

