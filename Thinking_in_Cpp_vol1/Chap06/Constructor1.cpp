//: C06:Constructor1.cpp  Constructors & destructors
#include <iostream>
using namespace std;

class Tree 
{
  float height,growth_rate;  //I expand the example of the book, by using an extra variable growth_rate
public:
  Tree(float initialHeight, float rate);  // Constructor
  ~Tree();  // Destructor
  void grow(int years);
  void printsize();
};

Tree::Tree(float initialHeight,float rate) //Constructor details
{  height = initialHeight; growth_rate = rate; }

Tree::~Tree()                     //Destructor details
{  cout << "We will destroy Tree :" << endl;  printsize(); }

void Tree::grow(int years) 
{  height += (growth_rate*years); }

void Tree::printsize() 
{  cout << "Tree height is " << height << endl; }

int main() 
{
  cout << "before opening brace" << endl;
  {
    Tree t(12,0.5);
    cout << "  after Tree creation" << endl;
    t.printsize();
    t.grow(4);
    cout << "  before closing brace" << endl;
  }
  cout << "after closing brace" << endl;
}
