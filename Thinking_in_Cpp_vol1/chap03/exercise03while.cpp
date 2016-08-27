// I chose to implement a menu-like system. 
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string word;
    while(true) 
    {
        cout << "  Enter a choice : \n"  
            << " \"Copy\" to copy files \n"
            << " \"Delete\" to delete files \n"
            << " \"Quit\" to exit program." << endl;
        cin >> word ;
        if(word == "Quit" || word == "quit" ) { cout << "exiting " << endl; break; }
        else if (word == "Copy" or word == "copy" )
            cout << "\tSo you want to copy files!" << endl;
        else if (word == "Delete" or word == "delete" )
            cout << "\tBe careful not to delete the wrong files!" << endl;
        else cout << "\tInvalid choice " << word << endl;
    }
    return 0;
}
//g++ -o exercise03while exercise03while.cpp
/*  ******** A text to use : exercise03text.txt
word1 word2
Delete copy
Copy 
quit
****** as input for the program  *** */
./exercise03while < exercise03text.txt
