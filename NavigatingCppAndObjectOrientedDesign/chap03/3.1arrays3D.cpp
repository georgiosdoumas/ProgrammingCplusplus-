#include <iostream>
using namespace std;
void f(int (*)[10][15] ,int ,int ,int);  //(function that takes as arguments a 3D array of ints,and 3 more integer parameters) 
//void f(int [][10][15] , int , int , int); //....or equivalently :
int main()
{
    int a[5][10][15];                       // 3D array of 5 x 10 x 20 ints
    int row,col,height;
    for (int r=0; r<5; r++) {               //populate the array in a nice way
        for (int c=0;c<10;c++) {
            for (int h=0;h<15;h++) a[r][c][h]=100*r+10*c+h;
        }
    }
    cout << a << " " << &a[0][0][0] << endl;    //output the initial memory address,in 2 different ways 
    cout << *(&a[0][0][0]) << endl;   // output the value of 1st element
    cout << "Give row column height (3 integers seperated by space , r<5,c<10,h<15) : ";
    cin >> row >> col >> height ;
    f(a,row,col,height);                     // call function with 3D array,and position for element to show
    //f(&(a[0][0][0]),row,col,height);           //error! this does not compile
    return 0;
}
void f(int (*p)[10][15] ,int i,int j,int k) // 3D function definition (can use either this line or the next)
//void f(int p[][10][15] ,int i,int j,int k)   
{
   cout << p << " " << &p[0][0][0] << endl;   //ok , the same memory addresses appear
   cout << *(&p[0][0][0]) << endl;   // value of 1st array element
   cout << p[i][j][k] << endl;                   // 3D array subscript,value of element i-j-k
   cout << *(&p[0][0][0] + 10 * 15 * i + 15 * j + k) << endl;  //another way for the same element
}
