#include <iostream>
int main() 
{
    int var1=10,var2=20; 
    int * pvar;  
    pvar=&var1;
    std::cout << "pvar points to var1 , so *pvar=" << *pvar << " and it points to address of var1,which is &var1=pvar=" 
              << pvar << std::endl;
    var1=3;
    std::cout << "we changed value of var1 but pvar still points to it,so *pvar=" << *pvar 
              << " and address of var1 still is &var1=pvar=" << pvar << std::endl;
    pvar=&var2;
    std::cout << "pvar now points to var2,so *pvar=" << *pvar << " and it points to address of var2,which is &var2=pvar=" 
              << pvar << std::endl;
    std::cout << "The pointer himself is always located in position " << &pvar << std::endl;
    return 0;
}
