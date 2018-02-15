#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using std::vector;
class lineSegment
{
  private:
    vector<double> point1 {0.0, 0.0};
    vector<double> point2 {0.0, 0.0};
  public:
    lineSegment(const vector<double> pnt1,const vector<double> pnt2)
    {
      assert(pnt1.size()==2 && pnt2.size()==2);
      std::cout << "Full vector Constructor called " << std::endl;
      point1.push_back(pnt1[0]);
      point1.push_back(pnt1[1]);
      point2.push_back(pnt1[0]);
      point2.push_back(pnt1[1]);
    }
};
