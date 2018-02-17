#ifndef BOX_H
#define BOX_H
#include <iostream>
 
class Box
{
	private:
		double length {1.0};
		double width {1.0};
		double height {1.0};
 
	public:
	// Constructors
		Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv} {}
		Box() {} 			// No-arg constructor
   // Copy constructor
		Box(const Box& box): length {box.length}, width {box.width}, height {box.height} {}
   // Function to calculate the volume
		double volume() const  { return length*width*height; }
// Accessors
		double getLength() const { return length; }
		double getWidth() const { return width; }
		double getHeight() const { return height; }
 // Less-than operator, implement it as a Class function :
		bool operator<(const Box& aBox) const  { return volume() < aBox.volume(); } // for box1<box2
		bool operator<(double aValue) const;													// for box1<value
};

inline bool Box::operator<(double aValue) const
{ return volume() < aValue; }

inline bool operator<( double aValue, const Box &box2) 					// for value<box2
{ return aValue < box2.volume() ; }
#endif
