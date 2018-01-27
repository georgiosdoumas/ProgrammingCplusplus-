/* Exercise 7.27: Add the move, set, and display operations to your version of Screen. 
Test your class by executing the following code:
Screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);  cout << "\n";
myScreen.display(cout); cout << "\n"; */
// I am using my solution of Exercise7.23 and Exercise7.24.cpp as a base. But here, to practice the 
// multiple-files, I keep the class separate from the functions and the main.

#include <iostream>
#include <string> 
using std::cin; using std::cout; using std::endl; using std::string;

class Screen {
    public:
        typedef string::size_type pos;
        Screen() = default;         
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
        
        char get() const { return contents[cursor]; }   // get the character at the cursor.Defined in class, so automatically inline
        char get(pos ht, pos wd) const;  // will make it inline at the other file functions.cpp , with the definitions
        Screen& move(pos r, pos c);             // do not know how to make it inline. See comment at functions.cpp file
        Screen& set(char);
        Screen& set(pos, pos, char);
        Screen &display(std::ostream &os) { do_display(os); return *this; }
        const Screen &display(std::ostream &os) const  { do_display(os); return *this; }
        
    private:
        pos cursor = 0;
        pos height {0}, width {0};
        string contents;
        
        void do_display(std::ostream &os) const {os << contents;}
};

// 
