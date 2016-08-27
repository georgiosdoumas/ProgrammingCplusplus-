#include <iostream>
using namespace std;
int main() 
{
    char choice; // To hold users response
    bool quiting = false; 
    while(true)
    {
        cout << "MAIN MENU:" << endl;
        cout << "l: left, r: right, q: quit -> ";
        cin >> choice;
        switch(choice) 
        {
            case 'q' : quiting = true ; break;  //here continue is not good
            case 'l' : 
                      {  
                          cout << "\tLEFT MENU:" << endl;
                          cout << "\tselect a or b: "; cin >> choice; 
                          switch(choice)
                          {
                            case 'a' : cout << "\tyou chose 'a'" << endl; continue; //or break, has the same functionality!
                            case 'b' : cout << "\tyou chose 'b'" << endl; continue;
                            default  : cout << "\tyou didn't choose a or b!" << endl;  
                          } 
                        } 
                        continue;
            case 'r' : 
                        {
                            cout << "\tRIGHT MENU:" << endl; cout << "\tselect c or d: ";
                            cin >> choice; 
                            switch(choice)
                            {
                                case 'c' : cout << "\tyou chose 'c'" << endl; break; 
                                case 'd' : cout << "\tyou chose 'd'" << endl; break; 
                                default  : cout << "\tyou didn't choose c or d!" << endl; 
                            }
                        }
                        continue;
           default : cout << " you must type l or r or q!" << endl;
        }
         if(quiting==true) { cout << "quitting menu..." << endl; break; /* break out of while */}
     } 
    return 0;
}         
