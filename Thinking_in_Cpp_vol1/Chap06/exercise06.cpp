//: C06:Handle.cpp {O}
// Handle implementation for exercise 6
#include "exercise06.h"
#include "../require.h"
#include <iostream>
// Define Handle's implementation:
struct Handle::Cheshire 
{
  int i;
  std::string word;
};

Handle::Handle()
{
  smile = new Cheshire;
  smile->i = 0;
  smile->word = "";
}

Handle::~Handle()
{  std::cout << "Destructor will delete the member struct! Trust the destructor" << std:: endl; delete smile; }

int Handle::read() 
{  std::cout<< smile->word << std::endl; return smile->i; }

void Handle::change(int x) 
{  smile->i = x; smile->word = "changed"; } 
