// Professional C++ 3rd Ed, Chap 02 page 54 Numeric Conversions , and refreshing what was presented on page 6: The main() Function
#include <iostream>
#include <string> 
int main(int argc, char* argv[])
{
    if(argc > 1 ) {
      for (int i {} ; i < argc ; ++i)
        std::cout << argv[i] << std::endl;
     }
    int age {};
    if(argc ==3)  
      age = std::stoi(argv[2]);
    std::cout << "Hello " << argv[1] << ", I suppose you are " << age << " years old." << std::endl;
}
// g++ -Wall -std=c++11 -o page54Numericonversions page54Numericonversions.cpp
/* Call it like this : 
./page54Numericonversions  George 44   
To see the errors printed out , call it also in this way 
./page54Numericonversions  32 Nick 
*/
