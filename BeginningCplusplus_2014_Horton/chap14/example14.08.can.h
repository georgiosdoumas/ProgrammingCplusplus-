#ifndef CAN_H
#define  CAN_H
#include  "example14.08.vessel.h"
const double pi {3.14159265};

class  Can : public Vessel
{
protected:
  double diameter {1.0};
  double height {1.0};
  //constexpr static double pi {3.14159265};

public:
  Can(double d, double h) : diameter {d}, height {h} {}

  double volume() const override { return pi*diameter*diameter*height/ 4.0; }
};
#endif
