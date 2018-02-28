// My variation of the books example, to see if I could dynamicaly build a string for the message
#include <iostream>
#include <string>  // also for the functions to_str(...) and  ....c_str()
int main()
{
  for (size_t i {}; i < 8; ++i)
  {
    try
    {
      if (i < 3)  throw i;

      std::cout << " i not thrown - value is " << i << std::endl;

      if (i > 5)
      {
        std::string s = std::to_string(i);
        std::string excepmsg = "Here is another!From i="+s;
        throw excepmsg.c_str();    // convert the string excepmsg to a C-style const char*
      }
      std::cout << " End of the try block." << std::endl;
    }
    catch (const char* message)
    {   // Catch exceptions of type char*
      std::cout << " \"" << message << "\" caught " << std::endl;
    }
    catch (size_t i)
    {  // Catch exceptions of type size_t
      std::cout << " i caught - value is " << i << std::endl;
    }

    std::cout << "End of the for loop body (after the catch blocks) - i is " << i << std::endl;
  }
}
