// A combination of what is mentioned on 1.5.5 and A.2.5 filling what is missing from the text, 
// like header <string> 
#include <iostream>
#include <string>
using std::cout;
int main (int argc, char* argv[])
{
    for (int i= 0; i < argc; ++i)
        cout << argv[i] << '\n';
    if(argc > 2)
      cout << argv[1] << " times " << argv[2] << " is " << std::stof(argv[1]) * std::stof(argv[2]) << std::endl;
    return 0;
}

// /usr/bin/g++ -Wall -std=c++11 1.5.5.main_arg.cpp -o 1.5.5.main_arg
// ./1.5.5.main_arg 3.9 2.8 
// but we can even call it this way (due to the way stof() operates, it will ignore the extra letters after the number) : 
// ./1.5.5.main_arg 3.9a 2.8vd 
