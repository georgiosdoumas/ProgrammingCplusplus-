//  Fifo implementation
#include <iostream>
#include "4.2Fifo4.h"
using namespace std;
void Fifo::write(char c) 					// write char to Fifo
{
	if (full()) { cout << this->nitems() ; throw " items.Fifo is full";  }
	else {
		count++;
		if (rear == Fifo_max)  rear = 0;			// reached the end? wrap around
		s[rear++] = c;
	}
}
char Fifo::read() 							// read char from Fifo
{
	if (empty()) throw "Fifo is empty";
	else {
		count--; 
		if (front == Fifo_max)	front = 0;			// reached the end? wrap around
	}
	return s[front++];
}
