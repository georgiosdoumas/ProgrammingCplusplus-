/* Exercise 11.7: Define a map for which the key is the family’s last name and the value
is a vector of the children’s names. Write code to add new families and to add new
children to an existing family. */

#include <map>
#include <string>
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string;

int main(int argc, char* argv[])
{
  std::vector<string> gellersChildren {"George","Adam","Anna"};
  std::map<string, std::vector<string>> familychildren { { "Smiths", {"Mary","John"} },
                                                         { "Gellers", gellersChildren } };
  std::vector<string> newchildren {"Nick","Elen"};
  //familychildren.insert("Brians", newchildren);  // compile error! Honestly I am surprised. So I tried the next line:
  familychildren["Brians"] = newchildren;  // OK this is accepted by the compiler.
  for(const auto & familychilds : familychildren)
  {
     cout << familychilds.first << " have as children: " ;  //Brians are typed first, then Gellers, then Smiths! Map is ordered
     for( const auto & childname : familychilds.second)
       cout << childname << ", " ;
     cout << endl;
  }
  // Now that I understood the basics of adding , I will ask the user for input:
  string newfamilyname;
  newchildren.clear();
  cout << " Enter a new family name " ;
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
     familychildren[newfamilyname] = newchildren;
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

// g++ -Wall -std=c++11 Exercise11.07.cpp -o Exercise11.07
