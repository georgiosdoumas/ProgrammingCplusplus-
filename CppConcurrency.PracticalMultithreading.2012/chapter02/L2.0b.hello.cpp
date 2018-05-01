// Trying to extend what is mentioned on pages 16, 17
// At this point I do not know if it is possible to avoid global functions.
#include <iostream>
#include <string>
#include <thread>

void do_something(std::string text) 
 { std::cout << " I am a global function, doing something:"<< text << std::endl;}
void do_something_else() 
 { std::cout << " I am a global function, doing something else!" << std::endl;}
void print_message(std::string txt) {std::cout << "--" << txt <<"!" << std::endl;}

class backgroundTask
{
  private:
    std::string message;
  public:
    backgroundTask(std::string msg="default text"): message {msg} //constructor with a default text
     { }
	 void operator()() const
	 {
	   do_something(message);
	   do_something_else();
	 }
};

int main()
{
  std::string msg { " my message" };
  std::cout << "Lets create a class instance (a backgroundTask object)." <<std::endl;
  backgroundTask bt;
  std::cout << "Now we launch the thread..." << std::endl;
  std::thread bgThread(bt); 
  std::cout << "Now we call bgThread.join()" << std::endl;
  bgThread.join();
  std::cout << "Finished.But we do it again without creating a class instance:\n";
  backgroundTask btmsg(msg); 
  std::thread bgThreadMsg(btmsg); 
  bgThreadMsg.join();
  std::cout << "Finished.Once more, in one step:\n";
  std::thread bgThreadMsg2( (backgroundTask(" my new message")) );
  bgThreadMsg2.join();
  std::cout << "Finished.But we do it again with lambda expression:\n";
  std::thread prntThread( []{print_message(" Another message!");} );
  prntThread.join();
}
// /usr/bin/g++ -Wall -std=c++11 -o helloConcurent3 L2.0b.hello.cpp -pthread
