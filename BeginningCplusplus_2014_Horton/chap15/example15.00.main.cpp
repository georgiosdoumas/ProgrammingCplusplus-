// Making a working example from what is given on page 465
#include <iostream>
int main()
{
  int test;
  std::cout << "Enter a integer smaller than 6 :";
  while(std::cin >> test)
    try
    {
      if(test > 5)
        throw " Input is greater than 5"; // Throws an exception of type const char*
      std::cout << "An exception was not thrown! Good input.\n";
      std::cout << "So lets see what we can do with the good input!" << std::endl;
      std::cout << "Its square is " << test*test << std::endl;
      return 0;
    }
    catch(const char* exc_message)
    {
  //Code to handle the exception,executes if exception of type 'char*' or 'const char*' is thrown
      std::cout << exc_message << std::endl;
      std::cout << " Please enter a valid input.Integer smaller than 5:";
    }
  // if we reach here, then the result of cin>>test was not successful
    std::cout << "You did not even provided a number! I will not tolerate this. Bye." << std::endl;
}

