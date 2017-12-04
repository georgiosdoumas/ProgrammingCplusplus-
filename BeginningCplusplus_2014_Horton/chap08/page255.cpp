// Beginning C++ 2015 , practice on what is mentioned on page 255 with corrections on the code that the book has wrong
#include <iostream>
#include <vector>
template <typename T1, typename T2> auto vector_product(const std::vector<T1>& data1, const std::vector<T2>& data2) -> decltype(data1[0]*data2[0])
{
    if(data1.size() != data2.size()) return 0;      // Gaurd against unequal vectors
    decltype(data1[0]*data2[0]) sum {};
    for(size_t i {} ; i<data1.size() ; ++i) sum += data1[i]*data2[i];
    return sum;
}

int main()
{
    std::vector<int> iv1 { 3,6,9} ;
    std::vector<int> iv2 { 2,3,4};
    std::vector<int> iv {2,8};
    std::vector<double> dv1 { 3.1,6.2,9.3,12.5};
    std::vector<double> dv2 { 4.1,7.2,10.3,13.5};
    //auto sumint1 = vector_product(iv1, iv2); std::cout << sumint1 << std::endl;
    //auto sumdoub = vector_product(dv1, dv2); std::cout << sumdoub << std::endl;
    // But instead of the above linew we can even do it like this, if we do not care to save the result on a variable:
    std::cout << vector_product(iv1, iv2) << std::endl;
    std::cout << vector_product(dv1, dv2) << std::endl;
}
// g++ -Wall -std=c++11 -o page255 page255.cpp
