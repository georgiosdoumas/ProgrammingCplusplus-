#include <iostream>
#include <thread>

void hello()
{
  std::cout<<"Hello Concurrent World!\n" ;
}

int main()
{
  std::cout << "We compiled with option -pthread " << std::endl;
  std::thread printingthread( hello );
  std::cout << " Now we call join()" << std::endl;
  printingthread.join();
  std::cout << " We succeeded!" << std::endl;
}

// /usr/bin/g++ -Wall -std=c++11 -o helloConcurent L1.1.hello.cpp -pthread
