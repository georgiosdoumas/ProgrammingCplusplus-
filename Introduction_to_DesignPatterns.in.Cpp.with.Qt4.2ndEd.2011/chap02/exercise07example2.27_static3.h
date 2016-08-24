#ifndef _STATIC_3_H_
#define _STATIC_3_H_
#include <string>
using namespace std;

class Client 
{
 private:
    string m_Name;
    int m_ID;
    static int s_SavedID ;
 public:
    Client(string name) : m_Name(name), m_ID(s_SavedID++)
     { }
     
    //static int getSavedID() //this is how the book has it (function has file scope), but it gives compile error
    int getSavedID()   //this compiles correctly, why would we want to have a static function as book proposes?
    {
        if(s_SavedID > m_ID) return s_SavedID;
        else return 0;
    }
    string getName() 
     { return m_Name; }
    int getID() 
     { return m_ID; }
};
#endif
