#include <iostream>
class Simple 
{
    private : int number;
    public : 
        Simple(int input);  //the program is so simple,that I will not implement those in a seperate file
        ~Simple();
};
//Implementations of constructor and destructor : 
Simple::Simple(int input)
{
    number = input;
    std::cout << "   Created an instance of the class,with member element of value : " << number << std::endl; 
}
Simple::~Simple()
{ std::cout << "  Destroying instance of class with member of value : " << number << std::endl; }

int main ()
{
    //Simple one;  //compiler error , because there is not a default constructor now,only a constructor that takes input is available! 
    std::cout << "Main program starts here!" << std::endl;
    Simple one(11);
    std::cout << "Main program will now end with a line that says return 0!" << std::endl;
    return 0;
}
