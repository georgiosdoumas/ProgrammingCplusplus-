/* Exercise 7.27: Add the move, set, and display operations to your version of Screen. 
Test your class by executing the following code:
Screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);  cout << "\n";
myScreen.display(cout); cout << "\n"; */

#include "Exercise7.27class.h"
//Through the above header , the <iostream> and <string> are included, as also the using std::stuff 
int main() 
{   
    Screen emptyscreen ;
    const Screen linescreen(1,3,'z');     // we cannot use the set() on this Screen object. But we cannot also use move() on it!
    for(int i=0;i<3; ++i) { cout << linescreen.get(0,i) ; cout << "_"; } 
    cout<<endl;
    //for(int i=0;i<3; ++i) { linescreen.move(0,i) ; cout<<linescreen.get() ; cout<<","; } //for const linescreen, this doesn't compile
    //cout<<endl;
    linescreen.display(cout); cout << "\n";   //trying the new way , using function display 
    Screen smallscreen(2, 5, 's');
    cout << smallscreen.get() ; cout << endl;  // prints last character s , at position  1,4. But lets see both lines
    for(int i=0;i<5; ++i) { cout << smallscreen.get(0,i) ; cout << "-"; }  // s-s-s-s-s-   this is the 1st line 
    cout<<endl;
    for(int i=0;i<5; ++i) { cout << smallscreen.get(1,i) ; cout << "-"; }  // s-s-s-s-s-   this is the 2nd line
    cout<<endl;
    cout << "Unfortunately,the new way of output with display function, prints multiple-line screens in a single line" << endl;
    smallscreen.move(1,2).set('#').display(cout);  cout << endl;
    smallscreen.move(0,0).set('#') ;  //Lets do something similar in 2 steps 
    smallscreen.display(cout); cout << "\n"; 
	return 0;
}

// g++ -Wall -std=c++11 -o Exercise7.27 Exercise7.27functions.cpp Exercise7.27main.cpp
