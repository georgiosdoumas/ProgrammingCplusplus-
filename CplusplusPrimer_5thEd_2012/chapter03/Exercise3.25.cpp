/* Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.
 // count the number of grades by clusters of ten: 0--9, 10--19, . .. 90--99, 100
 vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
 unsigned grade;
 while (cin >> grade) {     // read the grades
   if (grade <= 100)        // handle only valid grades
     ++scores[grade/10];    // increment the counter for the current cluster
}
*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; 
using std::vector; 
int main() 
{
    vector<unsigned> scores; 
    vector<unsigned> scorelevels(11,0); // 11 buckets, for [0-9],[10-19],...[90-99],100,  all initially 0
    unsigned grade;
    auto levelstart=scorelevels.begin();
    auto levelend=scorelevels.end();    
    cout << "Enter all grades as a series of space-seperated integers, with values of 1-100 (end with Ctrl+d) : " << endl; 
    while (cin >> grade)     // read the grades into vector scores
    {
        if (grade <= 100)        // handle only valid grades
          scores.push_back(grade);
    }
    for (auto iter=scores.begin(); iter < scores.end(); ++iter ) 
       ++(*(levelstart + ((*iter)/10) ) ) ;     //that is an ungly way to do it, and I do not know if Lipman has a simpler way in his mind
    cout << "The number of students with grades in each range of the 11 ranges [0-9],[10-19],...[90-99],100 are : " << endl;
    for (auto iter=levelstart; iter < levelend ; ++iter ) cout << *iter << " " ;
    cout << endl;    
    for (auto i : scorelevels ) cout << i << " " ;  //a simpler way to output the results
    cout << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise3.25 Exercise3.25.cpp 
