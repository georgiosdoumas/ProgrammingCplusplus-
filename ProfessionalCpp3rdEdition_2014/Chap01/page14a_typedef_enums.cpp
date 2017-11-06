// Professional C++ 3rd Ed , Chap 01 page 14 simple enumerators, similar to C
#include <iostream>
int main()
{
	enum PieceType {PieceTypeKing=1, PieceTypeQueen, PieceTypeRook=10, PieceTypePawn}; //no need for: typedef enum PieceType, as in C
	PieceType somePiece;
	//somePiece = 1; 	//compiler error, so we have to use the next line
	somePiece = PieceTypeKing; //only this is acceptable now!
	PieceType anotherPiece = PieceTypePawn; //it has value 11 , next value of PieceTypeRook 
	std::cout << somePiece << std::endl;  //this  compiles! But compare with next exercise page14stronglyEnum.cpp
	std::cout << PieceTypeQueen << std::endl;
	//We can also use more strictly these casts, presented in chapter 10, 
	//but in other books like C++ Primer (or Beginning C++) they appear in early chapters
	std::cout << static_cast<int> (somePiece) << " is the value of somePiece." << std::endl; 
	std::cout << static_cast<int> (anotherPiece) << " is the value of anotherPiece." << std::endl;
	return 0;
}
//g++ -Wall -std=c++11 -o page14a_typedef_enums page14a_typedef_enums.cpp
