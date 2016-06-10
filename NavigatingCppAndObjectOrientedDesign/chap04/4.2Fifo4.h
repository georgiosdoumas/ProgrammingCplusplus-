#ifndef FIFOH
#define FIFOH
// Fifo class
const int Fifo_max = 15;
class Fifo {
private:
	char s[Fifo_max];									// holds char data
	int front;											// read placeholder
	int rear;											// write placeholder
	int count;											// current number of chars
public:
	void init() { front = rear = count = 0; }
	int nitems() { return count; }
	bool full() { return count == Fifo_max; }
	bool empty() { return count == 0; }
	void write(char);									// write char to Fifo, for implementation see file 4.2Fifo.cpp
	char read();										// read char from Fifo , for implementation see file 4.2Fifo.cpp
};
#endif
