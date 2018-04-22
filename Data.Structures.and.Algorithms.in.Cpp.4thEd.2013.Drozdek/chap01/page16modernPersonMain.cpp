#include "page16modernPerson.h"
#include <iostream>

int main()
{
	
	modernPerson empty, node1("Roger",20), node2(node1);
	node2.setname("Wendy");  // if the correct copy constructor is not implemented, this would change the name of node1 too!
	node2.setage(30);
	
	//cout << empty.getname()<<" "<<empty.getage()<<endl;  // before the operatror<< overloading
	cout << empty ;
	empty = node1; // uses the assignment operator. NOTE: modernPerson empty = node1;  would use the copy constructor!
	empty.setname("George");  // if the correct assignment operator is not implemented, this would change the name of node1 too!
	empty.setage(45);
	//cout<<node1.getname()<<' '<<node1.getage()<<'\n'
	    // <<node2.getname()<<' '<<node2.getage()<<endl;
	//cout<<empty.getname()<<' '<<empty.getage()<<endl;
	cout << node1 << node2 << empty; 
	
}

// /usr/bin/g++ -Wall -std=c++11 -o page16 page16modernPersonMain.cpp
