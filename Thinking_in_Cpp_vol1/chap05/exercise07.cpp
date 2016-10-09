//I do not know the purpose of this exercise, I suppose it is just to get familiar with calling functions?
//The code is propably ungly , but with the knowledge of up to chapter 5 , I do not know if there can be better.
//I do not know if I could utilize friend functions! 
#include <iostream>
enum color {white,dark};
class Hen ;
class Nest;
class Egg
{
  private: color eggs_color;
  public: void display() { std::cout <<  ( (eggs_color==white)?" white " : " black ") ; }
          int getcolor() { return eggs_color; }
          void setcolor(color clr) { eggs_color = clr; }
};
class Nest
{
  private: int number_of_eggs; Egg nests_egg;
  public: 
          void display() 
          { 
             std::cout << "There are " << number_of_eggs << " eggs in the nest. Color is "; 
             nests_egg.display(); std::cout << std::endl; 
          }
          int get_eggs_number() { return number_of_eggs ; }
          void set_egg_num (int num) { number_of_eggs = num; }
          void set_nestegg_color(color clr) {nests_egg.setcolor(clr); }
};
class Henn
{
  private: std::string name; float weight; Nest his_nest;
  public: void display() 
          { 
            std::cout << name << " weighs " << weight << " kgr " << std::endl; 
            std::cout << " His nest has " << his_nest.get_eggs_number() << std::endl; 
            his_nest.display() ;
          }
          void give_name(std::string inputstr) { name = inputstr; }
          void set_weight(float mass) { weight = mass ; }
          void set_eggsnum (int num) { his_nest.set_egg_num(num) ; }
          void set_egg_color(color clr) { his_nest.set_nestegg_color(clr); }
};

int main()
{
    Henn henn1;
    henn1.give_name("rooster");
    henn1.set_weight(1.67); 
    henn1.set_eggsnum(4);
    henn1.set_egg_color(white);
    henn1.display();
}
