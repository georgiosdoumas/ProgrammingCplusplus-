#include <iostream>
#include <sstream>
#include <fstream>
int main() 
{
    using namespace std;
    ostringstream my_strbuf;  //string stream for output
    int lucky = 7;
    float pi=3.14;
    double e=2.71;
    cout << "An in-memory stream" << endl;
    my_strbuf << "luckynumber: " << lucky << endl
            << "pi: " << pi << endl
            << "e: " << e << endl;     //All these contents are "stuffed-into" the output-string-stream
    string strval = my_strbuf.str();   //...which in turn is assigned to std::string strval
    cout << strval;                    //at this point we got the first console output of contents of strval.
    string fileName;                  
    cout << "What file do you want to use for output? " ;
    cin >> fileName;                        //read a filename from user
    ifstream existing_file;           //try to open the file for reading, it will fail if file does not exist 
    existing_file.open( fileName.c_str() );
    if( existing_file ) //If the filename exists and opened successfully , ask user what to do
    {
        cout << "File exists, do you want to overwrite it ? (y/n) : " ;
        char ans;
        cin >> ans; 
        if(ans=='n') 
          { cout << "Exiting, without overwriting file. Run again,giving other filename." << endl; return 0;}  //file will close at exiting
    }  //else filename given by user does not exist , opening it for reading was a failure
    ofstream out_file;                  //Preparing a file object for output
    out_file.open( fileName.c_str() );   //binding the filename (must convert to constant string to pass it as filename), to the out_file object
    out_file << strval ;                //contents of strval are writen on this file
    out_file.close();
    
    cout << "\nRead data from the file - watch for errors." << endl;
    string newstr;
    ifstream inp_file;
    inp_file.open( fileName.c_str() );
    if(inp_file)        /*Make sure the file opened succesfully before attempting to read.*/
    { 
        int lucky2;
        inp_file >> newstr >> lucky2;  //reading from the opened input file, and assigning values to newstr="luckynumber:" , lucky2=7
        if (lucky != lucky2)  cerr << "ERROR! wrong " << newstr << lucky2 << endl;
        else  cout << newstr << " OK" << endl;
        float pi2;
        inp_file >> newstr >> pi2;   // again newstr is just to consume the title "pi:"
        if (pi2 != pi)  cerr << "ERROR! Wrong " << newstr << pi2 << endl;
        else  cout << newstr << " OK" << endl;
        double e2;
        inp_file >> newstr >> e2;
        if(e2!= e)  cerr << "ERROR: Wrong " << newstr << e2 << endl;
        else  cout << newstr << " OK" << endl;
        inp_file.close();
    }
    else cerr << "**Could not open file!!" << endl;  //how do I output the filename also? <<inp_file<<endl; was not good, gives 0 as filename
    
    cout << "\nRead from file line-by-line" << endl;
    inp_file.open( fileName.c_str() );
    if(inp_file) 
    {
        while (not inp_file.eof())       //as long as you have not reached the EndOfFile...
        {
            getline(inp_file, newstr);      // 3 pairs of word: number  will be read (whole lines)
            cout << newstr << endl;         //each iteration outputs the whole line (3 iterations until the EOF)
        }
        inp_file.close();
    }
    return 0;
}
