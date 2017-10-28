// Professional C++ 3rd Ed , Chap 01 page 26 , simple pointer examples
#include <iostream>
using namespace std;
// uncomment the several variations and compile-run each program one by one , and think on the results
/*
int main()
{
    int* non_initialized_p;
    // The following line compiles (with warning about uninitialized variable) 
    cout << non_initialized_p << " memory location is on the heap, with contents : " << cout << *non_initialized_p << endl;
    // but I noticed that the next line, I get slightly different result! I did not expect that
    cout << non_initialized_p << " memory location is on the heap, with contents : " << *non_initialized_p << endl;
    //after compiling, I run the program several times in a row, and noticed that the addresses allocated are always the same
    //something that does not happen in the next programs
    return 0;
}
*/
/*
int main()
{
    int* myIntegerPointer = nullptr;  // creating another pointer on the heap
    // next line produces a segm-fault immediately when the program is run, because *myIntegerPointer means: contents of a memory not-yet allocated
    //cout << myIntegerPointer << " memory location is on the heap, with contents: " << *myIntegerPointer << endl;
    cout << myIntegerPointer << " memory location is on the heap, but it has no contents yet! " << endl;
    myIntegerPointer = new int;  //only now some memory has been allocated on the heap for the pointer to exist
    cout << myIntegerPointer << " memory location is on the heap, with contents(before assigning): "; cout << *myIntegerPointer << endl;
    *myIntegerPointer = 27;
    cout << myIntegerPointer << " memory location is on the heap, with contents(after assigning): "; cout << *myIntegerPointer << endl;
    delete myIntegerPointer;   // what are the dangers of not having this line? Omit it and the program still compiles and executes.
    //so what did the deletion actually did? Lets see some output
    cout << myIntegerPointer << " memory location has been deleted, contents are "<< *myIntegerPointer << endl;  
    myIntegerPointer = nullptr;
    //cout << myIntegerPointer << " memory location has been set o nullptr, contents are "<< *myIntegerPointer << endl; //segm-fault on execution
    cout << myIntegerPointer << " memory location has been set o nullptr " << endl;  //this is ok
    return 0;
}
*/
/*
int main()  // trying with doubles
{
    double* pointer2double = new double ;  // we can skip the nullptr initialization,and do in 1 step what the previews program did in 2 steps
    *pointer2double = 37.6 ; 
    cout << pointer2double << " memory location is on the heap, with contents: " << *pointer2double << endl;
    delete pointer2double ;
    cout << pointer2double << " memory location is (after delete) still on the heap, with contents: " << *pointer2double << endl;
    pointer2double = nullptr; 
    cout << pointer2double << " memory location has been set to nullptr" << endl;
    return 0;
}
*/
/*
int main()
{
    double* pointer2double = new double ;  
    *pointer2double = 37.6 ; 
    cout << pointer2double << " memory location is on the heap, with contents: " << *pointer2double << endl;
    delete pointer2double ; // so what did the delete does? 
    cout << " we did a delete, and now we wil reassign " << endl;
    *pointer2double = 42.3;  // the pointer is still alive! 
    cout << pointer2double << " memory location is still on the heap, with contents: " << *pointer2double << endl;
    //double* pointer2double = new double; // compiler error, complains about previoulsy declared 
    //pointer2double = new double;   //
    pointer2double = nullptr; 
    cout << pointer2double << " memory location is still on the heap, but do NOT try to print its contents! " <<endl; 
    //cout << *pointer2double << endl; //.... because you will get segmentation fault! 
    return 0;
}
*/
///*
int main()
{
    double double_on_the_stack = 12.6;
    cout << &double_on_the_stack << " memory location is on the stack, with contents: "; cout << double_on_the_stack << endl;
    double* pointer2double = new double ;
    cout << pointer2double << " memory location is on the heap, with contents(before assigning): " << *pointer2double << endl;
    *pointer2double = 23.9;
    cout << pointer2double << " memory location is on the heap, with contents(after assigning): " << *pointer2double << endl;
    //Now we will do an assignement of a memory address from the stack to the pointer2double (initially created on the heap) 
    pointer2double = &double_on_the_stack ;         // it works, I was slightly surprised! 
    cout << pointer2double << " memory location is(?) on the heap(No!), with contents: " << *pointer2double << endl;
    //delete pointer2double ; // now there is no point to delete , and actually gives an execution error-  munmap_chunk(): invalid pointer
    return 0;
}
//*/
// g++ -Wall -std=c++11 -o page26pointer_examples page26pointer_examples.cpp
