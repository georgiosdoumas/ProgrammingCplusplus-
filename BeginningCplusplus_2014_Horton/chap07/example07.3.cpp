// Beginning C++ 2014 
// Ex7_03.cpp  Comparing strings. My implementation for the input loop, and a variation at the indexes on the swap loop
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::string;
int main()
{
    std::vector<string> names;      // Vector of names
    string input_name;              // Stores a name
    std::cout << "Enter first name: ";
    std::cin >> input_name; 
    do {
        names.push_back(input_name);   // ...add it to the vector
        std::cout << " enter another name (or Ctrl+d to finish): ";
     } while( std::cin >> input_name );
    // Sort the names in ascending sequence
    string temp;
    bool sorted {false};            // true when names are sorted
    while(!sorted)                  //if last action was : sorted=false , then we enter again the while-loop
    {
        sorted = true;          // we will run through the array, and if we do not swap any names, this will remain true
        for(size_t i {} ; i < names.size()-1 ; ++i)
        {
            if(names[i] > names[i+1])
            { // Out of order - so swap names
                temp = names[i+1];
                names[i+1] = names[i];
                names[i] = temp;
                sorted = false; //we had to swap 2 names, so we put it as false, and while(!sorted) will enter the loop again
            }
        }
    }
    size_t max_length{};                // Find the length of the longest name, for presentation purposes
    for(const auto& name : names)
      if(max_length < name.length()) max_length = name.length();
    // Output the sorted names 5 to a line
    std::cout <<"In ascending sequence the names you entered are:\n";
    size_t field_width = max_length + 2;  // have enough space for even the longest name
    size_t count {};
    for(const auto& name : names)
    {
        std::cout << std::setw(field_width) << name;
        if(!(++count % 5)) std::cout << std::endl;
    }
    std::cout << std::endl;
}
// g++ -Wall -std=c++11  -o example07.3 example07.3.cpp
