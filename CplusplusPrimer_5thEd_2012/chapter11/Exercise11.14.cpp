/* Exercise 11.14: Extend the map of children to their family name that you wrote for the
exercises in § 11.2.1 (p. 424) by having the vector store a pair that holds a child’s
name and birthday. */
// Using Exercise11.07 as a base
//#include <utility>  //compiles without it! Maybe because <map> is included?
#include <map>
#include <string>
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

int main()
{
  vector<std::pair<string,string>> gellersChildren { {"George","7 March"}, {"Adam","9 Aug"}, {"Anna","12 July"} };
  std::map< string, vector<std::pair<string,string>> > familychildren { { "Smiths", {{"Mary","6 Jan"}, {"John","8 Nov"}} },
                                                         { "Gellers", gellersChildren } };
  vector<std::pair<string,string>> newchildren { {"Nick","23 Oct"}, {"Elen","19 Feb"} };
  familychildren["Brians"] = newchildren;
  for(const auto & familychilds : familychildren)
  {
     cout << familychilds.first << " have as children:\n" ;
     for( const auto & childname : familychilds.second)
       cout << "  " << childname.first << ", with birthday:" << childname.second << endl ;
     cout << endl;
  }
  // ask the user for input:
  string newFamilyName, birthday;
  std::pair<string,string> newChildBirth;
  newchildren.clear();  // to use it for readings. It will hold pairs of newChildBirth
  cout << " Enter a new family name " ;
  while ( cin >> newFamilyName )
  {
     string child, birthday;
     cout << "  Enter name of 1st child and after space enter birthday, in form like: 14-Aug \n";
     cin >> newChildBirth.first >> newChildBirth.second;
     newchildren.push_back(newChildBirth);
     cout << "  Enter name and birthday of next child (or type . 0 to finish input) \n";
     while( cin >> newChildBirth.first >> newChildBirth.second)
     {
       if(newChildBirth.first == ".") break;
       newchildren.push_back(newChildBirth);
       cout << "  Enter name and birthday of next child (or type . 0 to finish input for this family name) \n";
     }
     familychildren[newFamilyName] = newchildren;
     newchildren.clear();
     cout << " Enter next family name , or hit ctrl+d to finish:";
  }
  cout << "\nAfter your additions, the families are now:" << endl;
  for(const auto & familychilds : familychildren)
  {
     cout << familychilds.first << " have as children:\n" ;
     for( const auto & childname : familychilds.second)
       cout << "  " << childname.first << ", with birthday:" << childname.second << endl ;
     cout << endl;
  }
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.14.cpp -o Exercise11.14
