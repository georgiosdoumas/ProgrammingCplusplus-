#include "exercise07example2.27static3.h"
#include <iostream>

int Client::s_SavedID(1000);

int main() 
{
    Client cust0("");  //a first customer with empty string , Client cust0() does not compile of course! 
    cout << cust0.getID() << endl;
    cout << cust0.getName() << endl; 
    Client cust1("George");
    cout << cust1.getID() << endl;
    cout << cust1.getName() << endl;  // cout << Client::getName() << endl;   is the text from book //compilation error
}

// g++ -o static3 exercise07example2.28static3.cpp 
./static3 
/******** Output ***** 
1000

1001
George
************/ 
