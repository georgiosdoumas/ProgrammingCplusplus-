#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() 
{
  vector<string> vlines;
  ifstream fin("text06.txt");
  string line,line_whole_text;
  while(getline(fin, line))
    vlines.push_back(line); // Each line is another i-th element of the vector vlines[i]
  for(int i = 0; i < vlines.size(); i++) 
  { 
     line_whole_text+=vlines[i]; 
     line_whole_text+=" ";   // or : line_whole_text+="\n";  //if we want to output new text lines normally
  }
  cout << line_whole_text << endl;
}

/* *******
contents of file06.txt
line one
second line here.
3rd line is this.
line number four, final line.
****** */
