/* Exercise 5.13: Each of the programs in the highlighted text on page 184 contains a
common programming error. Identify and correct each error.*/
#include <iostream>
#include <string> 
#include <vector> 
using std::cin; using std::cout; using std::endl; using std::string;
using std::vector; 
int main() 
{
	 /* (a) 
	 unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case ’a’: aCnt++;
        case ’e’: eCnt++;
        default: iouCnt++;
    }    // I suppose the above program is trying to count separately a then e, and then all 3 other vowels i,o,u
    */ 
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char next_text; cin >> next_text ; //I do this trick to avoid having a general function, because I want to compile+run the program
    char ch = next_text;
    switch (ch) {
        case 'a': aCnt++; break;
        case 'e': eCnt++; break;
        case 'i': case 'o': case 'u': iouCnt++; 
                  break; //That is how it should be to count only i,o,u and nothing else (not consonants, etc)
    }
    
    /* (b) 
    unsigned index = some_value(); //some_value() will be stimulated with a reading from user
    switch (index) {
        case 1:
            int ix = get_value();  //get_value() will be stimulated with a reading from user
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
    */
    vector<int> ivec(10,0);  // I could declare it empty, and then the error would be that in the cases the program should 
                             // have statements like ivec.push_back(index); but I also want to check other options for errors.
    unsigned some_value; cin >> some_value; // We have not yet learned a lot about functions (chapter 6) so I just do a cin
    unsigned index = some_value;
    switch (index) {
        int ix;  //It was error to declare and initialize it inside a case: 
        case 1:
            int get_value ; cin >> get_value ; 
            ix = get_value;
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
    
    /* (c) 
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
    */ 
    int get_num;
    cin >> get_num;
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num % 10;  // digit can now have a value 0,1,2,...,9 , NOT 10!
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddCnt++;
            break;
        case 2: case 4: case 6: case 8: case 0:  // against 0 should be the last check and not against 10 
            evenCnt++;
            break;
    }
    
    /* (d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
    */
    unsigned const ival=512, jval=1024, kval=4096; // The error was that they were not declared as const 
    unsigned bufsize;
    unsigned get_bufCnt ; cin >> get_bufCnt ; 
    unsigned swt = get_bufCnt;
    switch(swt) {
        case ival:		// now that ival is declared as const, it can serve as a case value
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
    cout << bufsize << endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise5.13 Exercise5.13.cpp 
