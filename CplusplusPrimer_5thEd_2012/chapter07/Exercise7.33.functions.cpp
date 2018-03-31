/* Exercise 7.33: What would happen if we gave Screen a size member defined as
follows? Fix any problems you identify.
pos Screen::size() const { return height * width; } */

#include "Exercise7.33.class.h"
void Window_mgr::clear(ScreenIndex i)
{
    Screen& scr = screensvec[i];         // scr is a reference to the Screen we want to clear
    scr.contents = string(scr.height * scr.width, '-');   // reset the contents of that Screen to all -
    //cout << "From inside the function clear(): " << endl;
    //cout << scr.contents << endl;
}
Window_mgr::Window_mgr (Screen& screen_element) 
{ screensvec.push_back(screen_element); } //now this constructor can be defined, Screen is fully defined in .h file
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screensvec.push_back(s);
	return screensvec.size() - 1;
}

Screen::pos Screen::size() const  // On an outside-class definition, we cannot just say pos. We have to say Screen::pos
{
	return height * width;
}
char Screen::get(pos r, pos c) const 
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
void Screen::do_display_2D(ostream &os) const 
{
    for (size_t i=0; i<height;++i)
    {
	 	for(size_t j=0; j<width; ++j) os << contents[i*width+j] ;
		os << "\n";
	 }
}
