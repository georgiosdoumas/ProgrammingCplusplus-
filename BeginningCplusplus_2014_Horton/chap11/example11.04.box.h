class Box
{
  private:
    double length;
    double width;
    double height;
  public:
// Constructors
    Box(double lv = 1.0, double wv = 1.0, double hv = 1.0);
    double volume(); // Function to calculate the volume of a box
    friend double surfaceArea(const Box& aBox); // Friend function for the surface area...
     //... only for demostration purposes, as an example of friend.
     // Could be better implemented similarly to the volume()
};
