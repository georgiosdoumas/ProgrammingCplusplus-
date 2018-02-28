// Making a working example from what is given on page 465
#include <iostream>
int main()
{
  int test;
  std::cout << "Enter a integer smaller than 5 :";
  while(std::cin >> test)
   try
   {
    if(test > 5)
      throw " Input is greater than 5"; // Throws an exception of type const char*
    std::cout << "An exception was not thrown! Good input.\n";
    break;
   }
   catch(const char* message)
   {
     //Code to handle the exception,executes if exception of type 'char*' or 'const char*' is thrown
    std::cout << message << std::endl;
    std::cout << " Please enter a valid input.Integer smaller than 5:";
   }
  //We could have enclosed the previews code in {} but it is not strictly needed on this case
  std::cout << "So lets see what we can do with the good input!" << std::endl;
  std::cout << "Its square is " << test*test << std::endl;
}
