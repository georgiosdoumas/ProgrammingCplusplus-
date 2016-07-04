#include <QTextStream>
#include <QString>
#include <QFile>
QTextStream qcout(stdout); //just give some name to remind us it has functionality similar to cout
QTextStream qcerr(stderr); //whatever name  I want, like cerr (no name conflict!), q_cerr, scream_err !
QTextStream qcin(stdin);
int main() 
{
    QString str1, newstr;
    QTextStream str_buf(&str1);  //"binding" object str_buf with address of string str1
    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;
    qcout << "An in-memory QTextStream" << flush;   //flush or endl is needed here
    str_buf << "luckynumber: " << lucky << endl   //all these contents of str_buf are put into str1
            << "pi: " << pi << endl
            << "e: " << e << endl;
    qcout << str1 << endl;                        //console output to see that str1 really has content
    
    QString fileName; 
    qcout << "What file do you want to use for output? " << flush ;  //flush or endl
    qcin >> fileName;                              //Read a filename from user
    QFile existing_file( fileName );  
    if( existing_file.open(QIODevice::ReadOnly) )      //If the file exists and opened successfully, ask user what to do
    {
        qcout << "File exists, do you want to overwrite it ? (y/n) : " << endl;
        QString ans;         //I could not get it work with:  char ans; qcin>>ans; if(ans=='n') {  ...  }
        qcin >> ans; 
        if(ans=="n") {
           qcout << "Exiting, without overwriting file. Run again,giving other filename.\n" << flush; 
           return 0;  //file closes at exiting, no need to close it manually
        }
        else 
          existing_file.close();       //closing it from ReadOnly mode, to open it as WriteOnly
    }  //else file given by user does not exist, opening it for reading was a failure, so we just go on.
    QFile data_file( fileName ); 
    data_file.open(QIODevice::WriteOnly);   //opening in write-only mode
    QTextStream out_put(&data_file);        //"binding" the opened[for writing] file to the object out_put
    out_put << str1 ;                    //writing contents of str1 to the opened file 
    data_file.close();
    
    qcout << "\nRead data from the file - watch for errors." << endl;
    if(data_file.open(QIODevice::ReadOnly))    //opening the same file in read-only mode
    {
        QTextStream input_file(&data_file);    //"binding" the opened[for reading] file to the object input_file
        int lucky2;
        input_file >> newstr >> lucky2; //read values from input_file (which is the opened data_file), assign them to newstr, lucky2
        if (lucky != lucky2)  qcerr << "ERROR! wrong " << newstr << lucky2 << endl;
        else  qcout << newstr << " OK" << endl;
        float pi2;
        input_file >> newstr >> pi2;            //newstr is for the title-word , pi2 is the number 
        if (pi2 != pi)  qcerr << "ERROR! Wrong " << newstr << pi2 << endl;
        else  qcout << newstr << " OK" << endl;
        double e2;
        input_file >> newstr >> e2;
        if (e2 != e)  qcerr << "ERROR: Wrong " << newstr << e2 << endl;
        else  qcout << newstr << " OK" << endl;
        data_file.close();
    }
    qcout << "\nRead from file line-by-line" << endl;
    if(data_file.open(QIODevice::ReadOnly)) 
    {
        QTextStream input_file(&data_file);
        while (not input_file.atEnd()) {
            newstr = input_file.readLine();      //here newstr is a whole line , with spaces.
            qcout << newstr << endl;            //outputs to the console 3 pairs of,  title: number
        }
        data_file.close();
    }
    return 0;
}
//Save the source file.cpp in a subdir , and while in that subdir give the commands
// qmake -project    //it will give the project a name similar to the subdir name
// qmake
// make
//If you do changes to the sourcefile.cpp , you only need to do 
// make
//after every change , to recompile
