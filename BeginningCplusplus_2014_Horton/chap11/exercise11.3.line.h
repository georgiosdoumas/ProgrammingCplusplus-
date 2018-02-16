#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using std::vector;
class lineSegment
{
  private:
    vector<double> point1 ;
    vector<double> point2 ;
  public:
    lineSegment(const vector<double> pnt1,const vector<double> pnt2)
    {
      assert(pnt1.size()==2 && pnt2.size()==2);
      std::cout << "Full vector Constructor called " << std::endl;
      point1.push_back(pnt1[0]); //point1[0]=pnt1[0]; //it compiles but at execution gives segmentation fault
      point1.push_back(pnt1[1]);
      point2.push_back(pnt2[0]);
      point2.push_back(pnt2[1]);
    }
    lineSegment(const vector<double> pnt2)
    {
      assert( pnt2.size()==2 );
      std::cout << "Special-implies point1 as (0,0)-constructor called " << std::endl;
      point1.push_back(0);
      point1.push_back(0);
      point2.push_back(pnt2[0]);
      point2.push_back(pnt2[1]);
    }
    lineSegment(const lineSegment &srclineSeg)
    {
      std::cout << "Copy Constructor called " << std::endl;
      point1.push_back(srclineSeg.point1[0]);
      point1.push_back(srclineSeg.point1[1]);
      point2.push_back(srclineSeg.point2[0]);
      point2.push_back(srclineSeg.point2[1]); 
    }
    double getLength () const
    {
      return sqrt( (point2[0]-point1[0])*(point2[0]-point1[0]) +
                   (point2[1]-point1[1])*(point2[1]-point1[1]) );
    }
    void present () const;
    int compare (const lineSegment &line2) const;  //passing by ref doesn't invoke copy constructor.Better!
    int compare (double somelength) const;
};

void lineSegment::present () const
{ std::cout<<" ("<<point1[0]<<","<<point1[1]<<") ("<<point2[0]<<","<<point2[1]<<") of length:"<<getLength()<<" "; }

int lineSegment::compare (const lineSegment &line2) const
{
  if ( getLength() < line2.getLength() ) return -1;
  if ( getLength() == line2.getLength() ) return 0;
  else return 1;
}

int lineSegment::compare (double somelength) const
{
  if ( getLength() < somelength ) return -1;
  if ( getLength() == somelength ) return 0;
  else return 1;
}
