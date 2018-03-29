are /* Exercise 7.23: Write your own version of the Screen class.
Exercise 7.24: Give your Screen class three constructors: a default constructor; 
a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; 
and a constructor that takes values for height, width, and a character, to use as the contents of the screen. */
#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

class Screen {
    public:
        typedef string::size_type pos;
        Screen() = default;         // needed, since we defining a constructor with parameters
    // On next constructor, the cursor initialized to 0 by its in-class initializer (see value at private member) 
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
        
        char get() const { return contents[cursor]; }  // get the character at the cursor. Defined in class, so automatically inline
        inline char get(pos ht, pos wd) const;  // explicitly inline function, defined outside of class
        Screen& move(pos r, pos c);             // can be made inline later, see the definition outside of class
    private:
        pos cursor = 0;
        pos height {0}, width {0};
        string contents;
};
char Screen::get(pos r, pos c) const // it has been declared as inline in the class, no need to repeat it
{
    pos row = r * width;            // compute row location
    return contents[row + c];       // return character at the given column
}
inline Screen& Screen::move(pos r, pos c)  // as we said, we can also specify inline on the definition only 
{
    pos row = r * width;        // compute the row location
    cursor = row + c;           // move cursor to the column within that row
    return *this;               // return this object as an lvalue
}

int main() 
{
    Screen emptyscreen ; 
    //Screen linescreen(0,3,'z');  //not logically good (unless we want to declare an empty line). Better have at least dimensions of 1,1
    Screen linescreen(1,3,'z');     //that is better. We actually have 1 line now , of 3 characters z
    for(int i=0;i<3; ++i) { cout << linescreen.get(0,i) ; cout << "_"; } 
    cout<<endl;
    for(int i=0;i<3; ++i) { linescreen.move(0,i) ; cout<<linescreen.get() ; cout <<","; } //another way to get the line
    cout<<endl;
    Screen smallscreen(2, 5, 's');
    cout << smallscreen.get() ; cout << endl;  // prints last character s, at position  1,4. But lets see both lines:
    for(int i=0;i<5; ++i) { cout << smallscreen.get(0,i) ; cout << "-"; }  // s-s-s-s-s-   this is the 1st line 
    cout<<endl;
    for(int i=0;i<5; ++i) { cout << smallscreen.get(1,i) ; cout << "-"; }  // s-s-s-s-s-   this is the 2nd line
    cout<<endl;
    smallscreen.move(1,3) ;                     // placing cursor on 2nd line 4th position  
    cout << smallscreen.get() ; cout << endl;   // prints z , of course
    smallscreen.move(0,4) ;                     // placing cursor on 1st line 5th position, last place on the line with character s
    cout << smallscreen.get() ; cout << endl;
    cout << smallscreen.get(0,6) ; cout << endl;  // even this prints s, we are actually on 2nd line 2nd position
    cout << smallscreen.get(0,9) ; cout << endl;  // last position inside smallscreen, still prints s, equivalent to smallscreen.get(1,4)
    cout << smallscreen.get(0,10) ; cout << endl;  //we are out of smallscreen now, prints empty character (or a garbage character)
    smallscreen.move(2,8) ;                     // we could even do bad things, there is no check for limits. It compiles...
    cout << smallscreen.get() ; cout << endl;   //...but it will print whatever garbage is on the memory location
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.24 Exercise7.24.cpp 
