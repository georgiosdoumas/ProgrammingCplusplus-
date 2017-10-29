// Professional C++ 3rd Ed , Chap 01 page 14, trying out the enum 
#include <iostream>
int main()
{
    enum PieceType { PieceTypeKing, PieceTypeQueen, PieceTypeRook, PieceTypePawn }; //no need for: typedef enum PieceType , as in C
    PieceType somePiece;
    //somePiece = 0; 	//compiler error, so we have to use the next line
    somePiece = PieceTypeKing; //only this is acceptable now!
    PieceType another = PieceTypePawn; //it has value 3 
    return 0;
}
//g++ -o page14a_typedef_enums page14a_typedef_enums.cpp
