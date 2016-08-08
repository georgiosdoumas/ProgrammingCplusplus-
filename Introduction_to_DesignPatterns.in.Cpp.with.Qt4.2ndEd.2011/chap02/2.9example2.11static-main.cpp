#include "2.9example2.9static.h"
#include <iostream>
int main() 
{
    Thing::showCount();
    Thing t1(3,4), t2(5,6);
    t1.showCount();
    std::cout << "Entering block,to create 2 local Things... " << std::endl;
     {
        Thing t3(7,8), t4(9,10);
        Thing::showCount();
     }
    std::cout << "Exited block (Things of local block {} were destroyed) " << std::endl; 
    Thing::showCount();
    return 0;
}
//g++ -Wall -o 2.9example2.11static-main 2.9example2.11static-main.cpp 2.9example2.10static.cpp
