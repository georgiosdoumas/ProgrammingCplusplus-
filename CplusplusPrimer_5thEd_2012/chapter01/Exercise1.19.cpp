#include <iostream>
//This incorporates tasks from exercises 1.9 and 1.10 
int main()
{
    std::cout << "Enter two integers :" << std::endl;
    int v1 = 0, v2 = 0, max, min, sum=0;
    std::cin >> v1 >> v2;  
    if (v1>v2) {max=v1; min=v2;} 
    else {max=v2; min=v1;} 
    int index = max;
    while (index >= min) 
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
