#include <iostream>
struct fat_int { int number; } ;
void global_func1(fat_int * pfi)
{
    int value;
    std::cout << "enter the integer value that you want to set in the struct data member: ";
    std::cin >> value;
    pfi->number = value;
}
void global_func2(fat_int * pfi)
{
    std::cout << pfi->number ;
}
int main ()
{
    fat_int fi;
    global_func1(&fi);
    std::cout << "The value of the only member of the struct is set to : " ;
    global_func2(&fi); 
    std::cout << std::endl;
    return 0;
}
