#include <iostream>
#include <cmath>
class lineSegment
{
  private:
    double point1[2] {0.0, 0.0}; //double point1[] {0.0, 0.0}; does not compile
    double point2[2] {0.0, 0.0};
  public:
    lineSegment(const double pnt1[],const double pnt2[])
     {
       //The following expression does not calculate the correct size:
       //std::cout<<"Size of passed array:"<< sizeof(pnt1)/sizeof(pnt1[1]) <<std::endl;
       //because pnt1 is just a copy of the pointer to the first element, so it has
       //same size as pnt1[0].
       //In an ordinary definition we could do :
       // double myarr[] = {1.2, 3.2};
       // std::cout << sizeof(myarr)/sizeof(myarr[0]) << std::endl;
       //and get the correct result of 2. But when we pass myarr as parameter
       //to a function, we loose that information. So we cannot check the correct
       //size of the passed point, eg see if it;s a good 2D point or an unacceptable 3D
       std::cout << "Full Constructor called " << std::endl;
       point1[0] = pnt1[0];
       point1[1] = pnt1[1];
       point2[0] = pnt2[0];
       point2[1] = pnt2[1];
     }
     lineSegment(double const pnt2[])
     {
       std::cout << "Special (implied 1st point) Constructor called " << std::endl;
       point2[0] = pnt2[0];
       point2[1] = pnt2[1];
     }
    lineSegment(const lineSegment &srclineSeg)
    {
      std::cout << "Copy Constructor called " << std::endl;
      point1[0] = srclineSeg.point1[0]; //point1[0] {srclineSeg.point1[0]};  does not compile
      point1[1] = srclineSeg.point1[1];
      point2[0] = srclineSeg.point2[0];
      point2[1] = srclineSeg.point2[1];
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
