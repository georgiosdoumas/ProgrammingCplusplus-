#include <iostream>
enum colors { blue=10 , green , red , yellow , black }; //global variable,so it is visible to the function colornames
void colornames(colors col)  //function to print name of color
{
    switch(col) 
    {
        case blue : std::cout <<"blue"; break; 
        case green : std::cout <<"green"; break;
        case red : std::cout <<"red";break;
        case yellow: std::cout <<"yellow";break;
        case black : std::cout <<"black";break;
    }
    std::cout << std::endl;
}
int main()
{
    
    colors mycolor;
    for(int i=blue; i<=black ; i++ ) //we can use i++, because we defined colors as consecutive integers starting  from 10
    {
      mycolor = static_cast<colors>(i);     //or the more simple : 
      //mycolor = colors(i);
      std::cout << i << " " ; colornames( mycolor ) ;
    }
    std::cout << std::endl;
    return 0;
}
