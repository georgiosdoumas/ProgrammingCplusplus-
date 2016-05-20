#include <iostream>
//This incorporates tasks from exercises 1.9 and 1.10 
int main()
{
    std::cout << "Enter two integers (first the smaller , then the bigger) :" << std::endl;
    int v1 = 0, v2 = 0,sum=0;
    std::cin >> v1 >> v2;  
    /*
     * according to what is presented in the book so far , we do not know how to organize the values of v1 and v2
     * so that v1<v2 , because the relational operators have not been shown , nor has the if statement 
    */
    int index = v2;
    while (index >= v1) 
    {
        std::cout << index << ",";
        sum += index;
        --index;
    }
    std::cout << std::endl;
    std::cout << "The sum of all integers between " << v1 << " and " << v2 << " is : " << sum 
              << std::endl;
    return 0;
}
