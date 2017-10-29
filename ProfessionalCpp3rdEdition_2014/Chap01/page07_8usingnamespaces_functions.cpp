// Professional C++ 3rd Ed , Chap 01 page 7-8
// no need to include <iostream> since it is included through the header 
#include "page07_8namespaces.h"  //function declaration of foo is on that header file. Implementation/definition is here
using std::cout;
namespace mycode_ns
{
    void foo() 
    {
	 cout << __func__ << " called in the mycode_ns namespace" << std::endl; //the __func__ is presented at page 22-23
    }
}
