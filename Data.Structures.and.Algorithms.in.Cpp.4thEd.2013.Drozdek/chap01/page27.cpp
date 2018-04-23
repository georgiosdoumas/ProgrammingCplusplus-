#include <iostream>
using namespace std;

class classf2 {
public:
    classf2 () { }
    double run (double x)
      {return 2*x;}
};
double sum3 (classf2 f, int n, int m) {
    double result = 0;
    for (int i = n; i <= m; i++) result += f.run(i);
    return result;
}

int main()
{
   classf2 myclass_instance;
   cout << sum3(classf2(),2,5) << endl; // 4+6+8+10 (only this way is shown in the book)    
   cout << sum3(myclass_instance,2,6) << endl;    // 4+6+8+10+12  (and I wanted to try this way)
   return 0;
}
