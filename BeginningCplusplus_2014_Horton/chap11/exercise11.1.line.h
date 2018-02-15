//#define COPYCONSTRDEBUG
#include <iostream>
#include <cmath>
class lineSegment
{
  private:
    double x1 {0.0};
    double y1 {0.0};
    double x2 {0.0};
    double y2 {0.0};
  public:
    lineSegment(const double pnt1[],const double pnt2[])
     {
       std::cout << "Constructor called " << std::endl;
       x1 = pnt1[0];
       y1 = pnt1[1];
       x2 = pnt2[0];
       y2 = pnt2[1];
     }
     lineSegment(const double pnt2[]): x2 {pnt2[0]}, y2 {pnt2[1]}
     {
       std::cout << "Special Constructor called " << std::endl;
     }
    lineSegment(const lineSegment &srclineSeg)
    {
      #ifdef COPYCONSTRDEBUG
        std::cout << "Copy Constructor called " << std::endl;
      #endif
      x1 = srclineSeg.x1; // x1  {srclineSeg.x1};  does not compile!
      y1 = srclineSeg.y1;
      x2 = srclineSeg.x2;
      y2 = srclineSeg.y2;
    }
    double getLength () const {return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );}
    void present () const;
    int compare (lineSegment line2) const;  //passing by value invokes the copy constructor.Not good
    int compare (double somelength) const;
};

void lineSegment::present () const
{ std::cout<<" ("<<x1<<","<<y1<<") ("<<x2<<","<<y2<<") with length:"<<getLength()<<" "; }

int lineSegment::compare (lineSegment line2) const
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
