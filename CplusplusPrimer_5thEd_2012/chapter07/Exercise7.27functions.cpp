/* Exercise 7.27: Add the move, set, and display operations to your version of Screen. 
Test your class by executing the following code:
Screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);  cout << "\n";
myScreen.display(cout); cout << "\n"; */

//NOTE: I cannot make the functions inline now that they are defined on different files from the class.h
// If I try to use keyword inline inside file class.h only , or only in file functions.cpp the compiler complains
// but also if I type the keyword inline in both class.h and functions.cpp , still the compiler complains.
// I do not remember if the book has mentioned anything about it, but maybe it will mention on a later chapter
// I am not sure if the fact that some functions are overloaded now , prohibit me from doing them inline.
// but I tried it also with only the move(), and still the compiler was complaining. So the question still remains...
#include "Exercise7.27class.h"
char Screen::get(pos r, pos c) const // 
{
    pos row = r * width;            // compute row location
    return contents[row + c];       // return character at the given column
}
Screen& Screen::move(pos r, pos c)  
{
    pos row = r * width;        // compute the row location
    cursor = row + c;           // move cursor to the column within that row
    return *this;               // return this object as an lvalue
}
Screen& Screen::set(char c)
{
    contents[cursor] = c;   // set the new value at the current cursor location
    return *this;           // return this object as an lvalue
}
Screen& Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch; // set specified location to given value
    return *this;               // return this object as an lvalue
}
