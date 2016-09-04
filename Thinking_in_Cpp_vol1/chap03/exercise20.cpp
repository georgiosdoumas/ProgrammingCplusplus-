#include <iostream>
using namespace std;

struct sThreeD_point { double x, y, z; } ;
typedef struct sThreeD_point ThreeDpoint;  //just to have more compact expressions
// typedef struct { double x, y, z; } ThreeDpoint ;   //faster way to achive what was done on the above 2 lines
int main() 
{
  ThreeDpoint points3d[10];
  //cout << "sizeof(ThreeDpoint) = " << sizeof(struct sThreeD_point) << endl; //same as next line
  cout << "sizeof(ThreeDpoint) = " << sizeof(ThreeDpoint) << endl;   //more clear expression, since we bothered to use typedef
  for(int i = 0; i < 10; i++) 
  {
    cout << "&points3d["<<i<<"] = " << (long)&points3d[i] << endl;
  }
  return 0;
}
