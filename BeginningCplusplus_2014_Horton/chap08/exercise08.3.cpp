//The author solves the exercise in a very interesting way, using switch! My solution is more simple with a direct approach.
#include <iostream>
int main (int argc, char * argv[] )
{
    if(argc<3 || argc >5) {
      std::cout << "Usage : " << argv[0] << " cmd-line-arg1 cmd-line-arg2 [ cmd-line-arg3 | cmd-line-line4 ] " << std::endl;
      std::cout << "Call this program with 2,3 or 4 command line arguments " << std::endl;
      return -1 ;
     }
    for (int i {1}; i < argc; ++i ) 
        std::cout << i << ": " << argv[i] << std::endl; 
}
// g++ -Wall -std=c++11 -o exercise08.3 exercise08.3.cpp
