#include <iostream>
using namespace std;
int main()
{
    int arr1[4], arr2[8];
    cout << "address of arr1[] " << long(arr1) << endl;
    cout << "address of arr2[] " << long(arr2) << endl;
    for(int i=0; i<8; i++) arr2[i]=20+i;  
    cout << "After initializing second array: " <<endl;
    for(int i=0; i<8; i++) cout << arr2[i] << " " ; cout << endl;
    cout << "Now lets initialize first array , but we will extend beyond its borders!" << endl;
    for(int i=0; i<9; i++) arr1[i]=10+i;  //bad! we should have a loop from 0 to 4 for arr1
    for(int i=0; i<4; i++) cout << arr1[i] << " " ; cout << endl;
    for(int i=0; i<8; i++) cout << arr2[i] << " " ; cout << endl;
    return 0;
}
