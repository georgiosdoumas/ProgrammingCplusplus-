// Carton.h
#ifndef CARTON_H
#define  CARTON_H
#include  <string>
#include  "example14.06.box.h"
using  std::string;

class  Carton : public Box
{
private:
  string material;

public:
  // Constructor  explicitly calling the  base constructor
  Carton(double lv, double wv, double hv, string str = "material") : Box {lv, wv, hv}, material {str}
  { }

  // Function  to  calculate the  volume of  a Carton object
  double volume() const override
  {
    double vol {(length - 0.5)*(width - 0.5)*(height - 0.5)};
    return vol > 0.0 ? vol : 0.0;
  }
  // I got the idea for my next function from what is mentioned on page 446 :
  //     double difference {static_cast<Box>(carton).volume() - carton.volume()};
  // but I did not wanted to implement it in main as an arithmetic calculation,
  // I thought it would be nice to make a member function from it, so I quckly thought that *this would be required
  double difference() const 
   { return static_cast<Box>(*this).volume() - volume(); };
};
#endif
