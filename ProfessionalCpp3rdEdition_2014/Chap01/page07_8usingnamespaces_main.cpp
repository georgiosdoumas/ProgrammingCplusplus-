// Professional C++ 3rd Ed , Chap 01 page 7-8, a complete working example of namespaces
#include "page07_8namespaces.h"
using namespace mycode_ns;
int main()
{
	foo(); // Implies mycode_ns::foo();
	return 0;
}
//g++ -o page07_8usingnamespaces page07_8usingnamespaces_functions.cpp page07_8usingnamespaces_main.cpp
//  ./page07_8usingnamespaces
