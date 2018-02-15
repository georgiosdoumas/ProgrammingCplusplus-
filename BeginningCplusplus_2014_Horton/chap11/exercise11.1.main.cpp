#include "exercise11.1.line.h"

int main()
{
  double pointA[] {3.2, 4.2};
  std::cout<<"Size of array for pointA:"<<sizeof(pointA)/sizeof(pointA[0]) <<std::endl;
  double const pointB[] {-1.3, 2.4};
  std::cout<<"Size of array for pointB:"<<sizeof(pointB)/sizeof(pointB[1]) <<std::endl;
  const double pointC[2] {};
  double pointD[2] {0, 1};
  lineSegment line1 {pointA, pointB};
  line1.present(); std::cout << std::endl;
  lineSegment const line2 {pointC, pointD};  // equal to: const lineSegment line2
  line2.present(); std::cout << std::endl;
  const lineSegment line3 { pointD};
  line3.present(); std::cout << std::endl;
  std::cout << "Lets compare lengths of the above line segments:" << std::endl;
  line1.present();
  if (line1.compare(line2) == -1)
    std::cout << " is shorter than ";
  else if (line1.compare(line2) == 0)
    std::cout << " has equal length to ";
  else std::cout << " is longer than ";
  line2.present(); std::cout<<std::endl;

  lineSegment line4 { pointC, pointD};
  line3.present();
  if (line3.compare(line4) == -1)  std::cout << " is shorter than ";
  else if (line3.compare(line4) == 0)  std::cout << " has equal length to ";
  else std::cout << " is longer than ";
  line4.present(); std::cout<<std::endl;

  double const  basiclength1 {2.36};
  int result1 {line3.compare(basiclength1)};
  line3.present();
  if (result1 == -1) std::cout << " is shorter than ";
  else if (result1 == 0) std::cout << " has equal length to ";
  else std::cout << " is longer than "; std::cout << basiclength1 <<std::endl;

  double basiclength2 {3.489};
  int result2 {line1.compare(basiclength2)};
  line1.present();
  if (result2 == -1) std::cout << " is shorter than ";
  else if (result1 == 0) std::cout << " has equal length to ";
  else std::cout << " is longer than "; std::cout << basiclength2 <<std::endl;
}
// /usr/bin/g++ -Wall -std=c++11 -o exercise11.1 exercise11.1.main.cpp
