#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() 
{
    vector<string> vwords;
    ifstream fin("text04");
    string line;
    while(getline(fin, line))
        vwords.push_back(line); // Add the line to the end
    // Print in reverse order adding initial line numbers:
    for(int i = vwords.size()-1 ; i >=0 ; i--)
    cout << i << ": " << vwords[i] << endl;
    return 0;
}
