#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    int target_word_count=0;
    ifstream fin("text04");
    string target_word="four";    
    string a_word;
    while( fin>>a_word  ) 
      { if(a_word == target_word) target_word_count++; }  //if was not mentioned in chapter 2 , but I cannot find a way to avoid using it here!
    cout << "Occurences of \"" << target_word << "\" in file text04, are " << target_word_count << endl;
    return 0;
}

/****
contents of file text04 :
some text , four
another occurence of four
four is 2 times in this line, four
Be carefull this line's four, is not counted,because it has a comma after it!
***/
