/* Exercise 7.36: The following initializer is in error. Identify and fix the problem.
struct X {
X (int i, int j): base(i), rem(base % j) { }
int rem, base;
}; */

struct X 
{
	X (int i, int j): base(i), rem(base % j) { }
	//int rem, base;
	int base, rem; //One way to fix it is to change the order of members
};
struct Y 
{
	//Y (int i, int j): base(i), rem(base % j) { }
	Y (int i, int j): rem(i % j), base(i) { } //OR mention only the parameter i and not another member. 
	                                          //I also fixed the initialize list order to reflect the members order. 
	int rem, base;
};

int main()
{}

// g++ -Wall -std=c++11 -o Exercise7.36 Exercise7.36.cpp
