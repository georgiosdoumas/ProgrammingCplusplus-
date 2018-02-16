#include "exercise11.3.line.h"

int main()
{
  vector <double> pointA {3.2, 4.2};
  vector <double> const pointB {-1.3, 2.4};
  const vector <double> pointC {0, 0};
  vector <double> const pointD {0, 1};
  lineSegment line1 {pointA, pointB};
  line1.present(); std::cout<<std::endl;
  lineSegment const line2 {pointC, pointD};  // equal to: const lineSegment line2
  line2.present(); std::cout<<std::endl;
  const lineSegment line3 { pointB };
  line3.present(); std::cout<<std::endl;
  lineSegment copiedline1 {line1};
  copiedline1.present(); std::cout<<std::endl;
}

// /usr/bin/g++ -Wall -std=c++11 -o exercise11.3.exe exercise11.3.main.cpp
