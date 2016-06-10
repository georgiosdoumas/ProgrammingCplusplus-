// cfifo4.C - character Fifos
#include <iostream>
#include <cstring>
#include "4.2Fifo4.h"
using namespace std;
int main()
{
    Fifo f;             // declare a Fifo
    int i, nc;
    f.init();												// initialize Fifo
	try {
		 const char *p = "data bytes:13";
		 nc = strlen(p);
		 for (i = 0; i < nc; i++)
			 f.write(*p++);										// write chars to Fifo
		 cout << f.nitems() << " characters in fifo:" << endl;
		 for (i = 0; i < nc; i++)
			 cout << f.read();									// read chars from Fifo
		 cout << endl;
	}
	catch (const char *msg) {
		cerr << msg << endl;
		return 1;
	}
	cout<< "No need to call init(),lets write some more characters in fifo,currently having "<< f.nitems() << " elements." <<endl;
	// write some more characters fifo will fill-up , and the exeption will happen
	try {
	    const char *s = "few more bytes";  //give a longer string , to see failure!
	    nc = strlen(s);
	    for (i = 0; i < nc; i++)
			 f.write(*s++);	        //at some point fifo will be full and the writing will not complete
        cout << f.nitems() << " characters in fifo" << endl;
		for (i = 0; i < nc; i++)
			 cout << f.read();				
		cout << endl;
	}
	catch (const char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}
