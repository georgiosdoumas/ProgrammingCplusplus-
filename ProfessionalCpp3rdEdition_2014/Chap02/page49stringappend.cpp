// Professional C++ 3rd Ed, Chap 02 page 49 and 50
//Implementing the function appendStrings and doing some other tests 

#include <iostream>
#include <cstring>

char* appendStrings(const char* str1, const char* str2, const char* str3)
{
  char* result = new char[strlen(str1) + strlen(str2) + strlen(str3) + 1];
  strcpy(result, str1);
  strcat(result, str2);
  strcat(result, str3);
  return result;
}

int main()
{
  char arr1[] = "professional "; // Compiler takes care of creating appropriate sized character array arr[]
  //char * word = "Programming " ;  // DANGEROUS! warning: deprecated conversion from string constant to ‘char*’  
  const char * word = "Programming " ;  // that is better
  char arr2[] = "in c++!";
  std::cout << appendStrings(arr1, word, arr2) << std::endl;
  arr1[0] = 'P';
  //word[0] = 'p'; //with char * word I would not get an error form this line BUT at execution I get segmentation fault! 
  arr2[3] = 'C';
  std::cout << appendStrings(arr1, word, arr2) << std::endl;
  return 0;
}
