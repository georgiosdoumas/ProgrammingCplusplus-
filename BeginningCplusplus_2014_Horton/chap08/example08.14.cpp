// Ex8_14.cpp Using a function template , and expanding on what is mentioned on pages 249-252
#include <iostream>
#include <vector>
#include <string>
 // Function template prototype
template <typename generictype> generictype larger(generictype a, generictype b); // just to show that using T is not obligatory! 
  // Template specialization for a different behavior in case pf pointer parameters passed
template <> long* larger<long*>(long* pa, long* pb)
{
    return *pa > *pb ? pa : pb;
}
// Overloading the template with 2 other templates of same name (larger) but different signature 
template <typename generictype> generictype larger (const generictype data[], size_t count) ;
template <typename T> T larger (const std::vector<T>& data) ;
 
int main()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;  // the function instance created above is used again here
 
    int a_int {35}, b_int {45};         // a 2nd function instance will be created :
    std::cout << "Larger of " << a_int << " and " << b_int << " is " << larger(a_int, b_int) << std::endl;
    long a_long {9L}, b_long {8L};      // a 3rd function instance will be created
    std::cout << "Larger of " << a_long << " and " << b_long << " is " << larger(a_long, b_long) << std::endl;
    //std::cout << "Larger of " << a_long << " and 9.5 is " << larger(a_long, 9.5) << std::endl;  // this does not compile
    std::cout << "Larger of " << a_long << " and 9.5 is " << larger<double>(a_long, 9.5) << std::endl; // This is how to do it. Outputs 9.5
    std::cout << "Larger of " << a_long << " and " << b_long << " is " << *larger(&a_long, &b_long) << std::endl;
    
    int iar[] { -2, 9, 4, 12 }; 
    double dar[] { -2.5, 9.2, 4.9, 12.96, 27.9 };
    std::cout << "Larger element of ints : " << larger(iar, sizeof(iar)/sizeof(iar[0]) ) << std::endl;
    std::cout << "Larger element of doubles : " << larger(dar, sizeof(dar)/sizeof(dar[0]) ) << std::endl;
    
    const char text[] {"A nod is as good as a wink to a blind horse."};
    std::cout << "Largest character in \"" << text << "\" is '" << larger(text, sizeof(text)) << "'" << std::endl;
 
    std::vector<std::string> words {"The", "higher", "the", "fewer"};
    std::cout << "The largest word in words is \"" << larger(words) << "\"" << std::endl;
}
 
// Template for functions to return the larger of two values
//remember that it is not even required to have the same names with the function declaration
template <typename T>  T larger(T a, T b)  // so here I choose to do less typing and use T instead of generictype 
{
    return a > b ? a : b;
}
template <typename T> T larger (const T data[], size_t count)
{
    T result {data[0]};
    for(size_t i {1} ; i < count ; ++i)
      if(data[i] > result) result = data[i];
    return result;
}
template <typename T> T larger (const std::vector<T>& data)
{
    T result {data[0]};
    for(auto& value : data)
      if(value > result) result = value;
    return result;
}

/*
/usr/bin/g++ -Wall -std=c++11 -o example08.14 example08.14.cpp
*/
