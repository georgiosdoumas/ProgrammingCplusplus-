// Throw an exception object. Variation of the book code to dynamically include the nymber i
#include <iostream>
#include "example15.03.mytroubles.h"

int main()
{
  for (int i {}; i < 3; ++i)
  {
    try
    {
      if (i == 0)
        throw Trouble {};
      else
        throw Trouble {"Nobody knows the "+std::to_string(i)+" troubles I've seen..."};
    }
    catch (const Trouble& t)
    {
      std::cout << "Exception: " << t.what() << std::endl;
    }
  }
}
