/* Exercise 11.23: Rewrite the map that stored vectors of children’s names with a key
that is the family last name for the exercises in § 11.2.1 (p. 424) to use a multimap. */
// Now we will be able to add a family with the same family-name as an existing one.
// Using Exercise11.07.cpp as my base

#include <map>
#include <string>
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string;

int main(int argc, char* argv[])
{
  std::vector<string> gellersChildren {"George","Adam","Anna"};
  std::multimap<string, std::vector<string>> familychildren { { "Smiths", {"Mary","John"} },
                                                         { "Gellers", gellersChildren } };
  std::vector<string> newchildren {"Nick","Elen"};
  //familychildren["Brians"] = newchildren;  // No [] on multimap! It's allowed to have another familychildren["Brians"]
  familychildren.insert({"Brians", newchildren});
  for(const auto & familychilds : familychildren)
  {
     cout << familychilds.first << " have as children: " ;
     for( const auto & childname : familychilds.second)
       cout << childname << ", " ;
     cout << endl;
  }
  // Now that I understood the basics of adding , I will ask the user for input:
  string newfamilyname;
  newchildren.clear();
  cout << " Enter a new family name (new family is allowed to have the same name as an existing family)" ;
  while ( cin >> newfamilyname )
  {
     cout << " Now enter the names of their children, in a single line, seperated by spaces\n";
     cout << "  and then Enter and just type a . at the next line, to finish this family input\n";
     string child;
     while( cin >> child)
     {
       if(child == ".") break;
       newchildren.push_back(child);
     }
     familychildren.insert({newfamilyname, newchildren});
     newchildren.clear();
     cout << " Enter next family name , or hit ctrl+d to finish:";
  }
  cout << "\nAfter your additions, the families are now:" << endl;
  for(const auto & familychilds : familychildren)
  {
     cout << familychilds.first << " have as children: " ;
     for( const auto & childname : familychilds.second)
       cout << childname << ", " ;
     cout << endl;
  }
  return 0;
}

// g++ -Wall -std=c++11 Exercise11.23.cpp -o Exercise11.23
