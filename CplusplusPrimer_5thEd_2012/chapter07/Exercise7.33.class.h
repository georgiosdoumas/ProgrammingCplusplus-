/* Exercise 7.33: What would happen if we gave Screen a size member defined as
follows? Fix any problems you identify.
pos Screen::size() const { return height * width; } */

#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; using std::ostream;

class Screen ; //must forward-declare class Screen here, since class Window_mgr will mention its name
class Window_mgr
{
  public:
    using ScreenIndex = vector<Screen>::size_type;     // location ID for each screen on the window
    void clear(ScreenIndex );                 // reset the Screen at the given position to all blanks
    Screen& get_screen(ScreenIndex i) { return screensvec[i]; } // a function I had to implement to have a useful main()
    Window_mgr() = default;
    Window_mgr (Screen& screen_element) ; //Declaring constructor. Cannot define here, because Screen is still incomplete-type
    ScreenIndex addScreen(const Screen&);  //from page 283 paragraph 7.4 
  private:
    vector<Screen> screensvec ;    //do not know how can I do better with this!
};
// now fully define class Screen
class Screen 
{
    friend void Window_mgr::clear(ScreenIndex); // clear() function can now access the private parts of class Screen
    public:
      typedef string::size_type pos;
      Screen() = default;         
      Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
      char get() const { return contents[cursor]; }   // defined inside class, so automatically inline
      inline char get(pos ht, pos wd) const;  // could also make it inline at the other file functions.cpp
      Screen& move(pos r, pos c);    //but I cannot make this (and next 2) inline, maybe because they return reference???       
      Screen& set(char);
      Screen& set(pos, pos, char);
      Screen& display(ostream &os) { do_display_2D(os); return *this; }
      const Screen &display(ostream &os) const  { do_display_2D(os); return *this; }
       
    private:
      pos cursor = 0;
      pos height {0}, width {0};
      string contents;
      pos size() const;   // for the shake of exercise7.33
      void do_display_2D(ostream &os) const; 
};
