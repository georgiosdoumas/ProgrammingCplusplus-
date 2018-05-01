#include <iostream>
#include <thread>

struct func
{
  int& i;
  func(int& inp ):i(inp) { }  //constructor
  void operator() ()
  {
	  for(unsigned j=1; j<100; ++j) 
	  {
		  if(j%10 == 0) std::cout << " We reached : " << j << std::endl;
		  std::cout << " And i=" << ++i << std::endl;	  
	  }
  }
};

void oops()
{
  int some_local_state=0;
  func my_func(some_local_state);
  std::thread my_thread(my_func);
  my_thread.detach();  // various outputs for a few j. Comment it out and uncomment next line ,build and run again.
  //my_thread.join();  //try it with join(), to see the whole output
  std::cout << " Exiting function oops().The thread may have not finished yet!" <<std::endl;
}

int main()
{
  oops();
}

// /usr/bin/g++ -Wall -std=c++11 -o localvars L2.1.localvars.cpp -pthread
