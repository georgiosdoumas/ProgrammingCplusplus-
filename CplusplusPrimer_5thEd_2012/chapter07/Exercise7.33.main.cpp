/* Exercise 7.33: What would happen if we gave Screen a size member defined as
follows? Fix any problems you identify.
pos Screen::size() const { return height * width; } */
// Very similar to Exercise7.32.main.cpp , but I got the chance to use the new size member of Screen
// and the Window_mgr function addScreen() 

#include "Exercise7.33.class.h"

int main() 
{
   Screen emptyscreen ;
   emptyscreen.display(cout); cout << ":This was just an empty screen! What did you expect to see?\n";
   
   const Screen clinescreen(1,3,'z');  //we cannot use the set() on this const object. And we cannot also use move() on it!
   clinescreen.display(cout); cout << " The above was a constant line-screen\n";  
   Screen bigscreen(3,4,'*');
   bigscreen.display(cout); cout << " And that was a 3x4 star screen\n";
   
   Screen smallscreen(2, 5, 's');   // 2 rows and 5 columns , positions from 0-1 for rows and 0-4 for columns
   //Window_mgr my_screens ; my_screens( smallscreen ); //NOT OK! Does not compile.I have to do it in a single step! 
   Window_mgr my_screens( smallscreen ); //that is OK! But I do not know how to add a 2nd element
   Window_mgr more_screens { smallscreen }; // also OK!
   Window_mgr::ScreenIndex wsize = my_screens.addScreen(clinescreen); 
   cout << "The last character of smallscreen is: ";
   cout << smallscreen.get() ; cout << endl;  // prints last character s , at position  1,4. 
   cout << "But lets see the whole smallscreen:" << endl;
   smallscreen.display(cout);  cout << endl;
   cout << "Now it is time for some changes on smallscreen. We show the results right after each change" <<endl;
   smallscreen.move(1,2).set('#').display(cout);  cout << endl;
   smallscreen.move(0,0).set('#').display(cout);  cout << endl;
   cout << "After the changes, the contents of the first Screen element of vector my_screens are intact:" << endl;
   my_screens.get_screen(0).display(cout);  cout << endl; 
   
   cout << "Lets clear the contents of handled smallscreen from the s characters " << endl;
   my_screens.clear(0); 
   cout << "Careful! The contents of smallscreen are still:" <<endl;
   smallscreen.display(cout);  cout << endl;
   cout << "But the contents of the first Screen element of vector my_screens have been reset to all - " <<endl;
   my_screens.get_screen(0).display(cout);  cout << endl;
   my_screens.get_screen(1).display(cout);  cout << endl;
   cout << "Lets clear the contents of the 2nd handled clinescreen : " << endl;
   my_screens.clear(wsize); 
   my_screens.get_screen(wsize).display(cout);  cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise7.33 Exercise7.33.functions.cpp Exercise7.33.main.cpp 
