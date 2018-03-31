/* Exercise 7.32: Define your own versions of Screen and Window_mgr in which
clear() is a member of Window_mgr and a friend of Screen. */
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
  private:
    //vector<Screen> screens{Screen(24, 80, ' ')}; // ERROR,compiler complains about this line! 
                                               //Because the members of class Screen are not yet known, we cannot have initialization
    vector<Screen> screensvec ;    //so I am forced to avoid the above in-class initialization and use this simple declaration
};
// now fully define class Screen
class Screen 
{
    friend void Window_mgr::clear(ScreenIndex); // clear() function can now access the private parts of class Screen
    public:
      typedef string::size_type pos; // it is important to have it here so that next lines can mention the name pos
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
      void do_display_2D(ostream &os) const; 
};
