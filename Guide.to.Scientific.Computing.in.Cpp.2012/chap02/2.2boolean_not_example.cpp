#include <iostream>
int main()
{
    int i=1; 
    char ans;
    bool completed = false;
    std::cout << "Did you finished?(y/n) ";
    std::cin >> ans;
    if(ans == 'y') 
       { completed = true; i++; }
    if (!completed)
       std::cout << "You must finish your project "<< i << " before moving to the next\n" ;
    else
       std::cout << "You can move on to project "<< i ;
    return 0;
}
