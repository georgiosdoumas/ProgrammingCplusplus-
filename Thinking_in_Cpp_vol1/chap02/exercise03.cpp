#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    int wordcount=0;
    ifstream fin("text03");
    string a_word;
    while( fin>>a_word ) wordcount++;
    cout << "Total number of words : " << wordcount << endl;
    return 0;
}
/* ******
contents of file text03

one two! three
four five six,
seven, eight,nine
real_nine.This_still_is_nine
ten...
***** */
