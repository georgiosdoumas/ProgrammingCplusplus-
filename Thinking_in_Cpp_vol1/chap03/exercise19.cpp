#include <iostream>
using namespace std;

int main() 
{
  int ar[10];
  char ch[4];
  double da[2];
  cout << "sizeof(int) = "<< sizeof(int) << endl;
  for(int i = 0; i < 9; i++)
    cout << "&ar[" << i << "] = " << (long)&ar[i] << endl;
  cout << "sizeof(char) = "<< sizeof(char) << endl;
  for(int i = 0; i < 4; i++)
    cout << "&ch[" << i << "] = " << (long)&ch[i] << endl;
  cout << "sizeof(double) = "<< sizeof(double) << endl;
  for(int i = 0; i < 2; i++)
    cout << "&da[" << i << "] = " << (long)&da[i] << endl;
}
