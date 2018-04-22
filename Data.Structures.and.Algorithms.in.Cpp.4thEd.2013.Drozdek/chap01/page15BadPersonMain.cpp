#include "page15BadPerson.h"
#include <iostream>

int main()
{
	badPerson node1("Roger",20), node2(node1); //or node2 = node1;
	strcpy(node2.pname,"Wendy");
	node2.age = 30;
	cout<<node1.pname<<' '<<node1.age<<' '<<node2.pname<<' '<<node2.age<<endl;
	
	goodPerson person1("George",45), person2(person1);
	strcpy(person2.pname, "Drozdek");
	person2.age = 58;
	cout<<person1.pname<<' '<<person1.age<<' '<<person2.pname<<' '<<person2.age<<endl;
}

// /usr/bin/g++ -Wall -std=c++11 -o page15 page15BadPersonMain.cpp
