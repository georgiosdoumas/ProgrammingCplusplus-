// Beginning C++ 2014 , my solution of exercise 7.1 
// where I did not want to ask the user for a y/n each time to let him add another student
// so I instruct him to enter a "." as a name to declare the end of input transactions.
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::string; using std::vector; using std::cin; using std::cout; using std::endl;

int main()
{
    vector<string> names;
    vector<size_t> grades;
    string name ;
    int grade {0};
    double sum {0.0};
    cout << "Enter the firstName   of the student:" ;
    do {
      cin >> name ;
      if ( name != "." ) names.push_back(name);
        else { cout<< "You finished your output by giving \".\"\n";break;}
      cout << "Enter the grade (an integer between 0-100) of " << name << ":" ;
      do {
        cin >> grade;
        if( grade >= 0 && grade <= 100 ) 
          { grades.push_back(grade); break; }
        else cout << "Please enter a grade between 0-100 :";
      } while (true); 
      
      cout << "Enter firstName  of next student [to end input give . (a simple dot) as a name]:" ;
    } while (true) ;
    for( size_t i {}; i<names.size() ; ++i )
    {
        cout<< std::setw(20) << names[i] << std::setw(5) << grades[i] ;
        sum+= grades[i];
        if ( (i+1)%3 == 0 ) cout << endl;
    }
    cout << "Average grade for the above students : " << sum/names.size() << endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o exercise07.1 exercise07.1.cpp
