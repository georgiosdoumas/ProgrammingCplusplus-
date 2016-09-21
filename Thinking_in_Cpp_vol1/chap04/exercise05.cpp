#include <iostream>
struct fat_int 
{ 
    int number; 
    void set(int i) { number = i;}
    void printnum() { std::cout << number; }
} ;
int main ()
{
    fat_int fi;
    int fi_n;
    std::cout << "enter the integer value that you want to set in the struct data member: ";
    std::cin >> fi_n;
    fi.set(fi_n);
    std::cout << "The value of the only member of the struct is set to : " ;
    fi.printnum();
    std::cout << std::endl;
    return 0;
}    
