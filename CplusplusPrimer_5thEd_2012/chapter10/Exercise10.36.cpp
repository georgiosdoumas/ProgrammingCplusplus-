/* Exercise 10.36: Use find to find the last element in a list of ints with value 0. */

#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
   std::vector<int> numbers1 { -1, 0, 5, 2, 3, 4, 0, -4, 9 }, numbers2 { 2, 3, 5 };
   auto lastzero = find(numbers1.crbegin(), numbers1.crend(), 0);
   if(lastzero != numbers1.crend())
   {
     std::cout << " From last found 0 to the end of the vector we have: \n";
     for(auto iter = lastzero.base(); iter != numbers1.cend(); ++iter)
        std::cout << *iter << " ";
    std::cout<<std::endl;
   }
   else std::cout << "Element 0 does not exist in the vector!\n";
   auto nozero = find(numbers2.crbegin(), numbers2.crend(), 0);
   if( nozero == numbers2.crend())  std::cout << " Element 0 not found in 2nd vector\n";
   return 0;
}

// g++ -Wall -std=c++11 Exercise10.36.cpp -o Exercise10.36
