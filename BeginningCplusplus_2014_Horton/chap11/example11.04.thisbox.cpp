// Implementing the ideas of pages 337-339
#include "example11.04.thisbox.h"
using std::string;
Box::Box(double lv, double wv, double hv, string clr) : length(lv), width(wv), height(hv), color(clr)
{ }

double Box::volume() const
{ return length*width*height; }

void Box::setColor(string newpaint) const // we can repaint (but not resize!) even a const box
{ color = newpaint; }

Box* Box::setLength(double lv)
{
  if(lv > 0) length = lv;
  return this;
}

Box* Box::setWidth(double wv)
{
  if(wv > 0) width = wv;
  return this;
}

Box* Box::setHeight(double hv)
{
  if(hv > 0) height = hv;
  return this;
}
