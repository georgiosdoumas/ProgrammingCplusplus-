#include <iostream>
#include <string>
using namespace std;  // for std::string , std::cout , std::cin

int main(int argc , char * argv[])
{
    const int size=5;
    string arrstr[size] ; 
    if(argc > 1) //User provided 1-5 words as command-line arguments
    {
        for(int i=0; i<size && i < argc-1; i++)
          arrstr[i] = string(argv[i+1]);  //simple way to convert the char array argv[] to a string
    }
    else //No cmd-line args. User will provide all 5 of them interactively
    {
        for(int i=0; i<size; i++) 
        {
            cout << "Enter string (one word): " ;
            cin >> arrstr[i] ; 
        }
    }
    for(int i=0; i<size; i++)  //Printing out the words in a single line
      cout << arrstr[i] << " " ;
    cout << endl;
    return 0;
}
