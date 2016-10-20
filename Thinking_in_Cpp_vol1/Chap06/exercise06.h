//: C06:Handle.h  Handle classes for exercise 6
#ifndef HANDLE_H
#define HANDLE_H
class Handle 
{
   struct Cheshire; // Class declaration only , just to be able to declare a pointer to it
   Cheshire* smile;
    public:
      Handle();
      ~Handle();
      int read();
      void change(int);
};
#endif // HANDLE_H 
