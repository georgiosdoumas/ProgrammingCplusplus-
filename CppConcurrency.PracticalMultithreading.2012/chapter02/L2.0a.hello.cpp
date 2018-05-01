// Trying to implement what is mentioned on pages 16, 17. I just do not feel good for usage of global functions! 
#include <iostream>
#include <thread>

void do_something() 
 { std::cout << " I am a global function, doing something."<< std::endl;}
void do_something_else() 
 { std::cout << " I am a global function, doing something else!" << std::endl;}

class backgroundTask
{
  public:
	 void operator()() const
	 {
	   do_something();
	   do_something_else();
	 }
};

int main()
{
  std::cout << "Lets create a class instance (a backgroundTask object)." <<std::endl;
  backgroundTask bt;
  std::cout << "Now we create the thread object ..." << std::endl;
  std::thread bgThread(bt); 
  std::cout << "Now we launch it by calling bgThread.join()" << std::endl;
  bgThread.join();
  std::cout << "Finished.But lets repeat it without creating a class instance\n";
  std::thread bgThread2 { backgroundTask() };
  bgThread2.join();
}
// /usr/bin/g++ -Wall -std=c++11 -o helloConcurent2 L2.0a.hello.cpp -pthread
