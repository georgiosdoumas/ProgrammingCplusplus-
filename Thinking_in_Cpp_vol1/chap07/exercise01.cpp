#include <iostream>
#include <string>
#include <fstream>
class Textclass 
{
    private: std::string textstream ;
    public:
        Textclass();
        Textclass( std::string filename_to_open);
        std::string contents();
};

Textclass::Textclass() { textstream="Default constructor created me\n"; } 
Textclass::Textclass( std::string filename_to_open) 
{
    std::ifstream inputfile ; inputfile.open( filename_to_open.c_str() );
    //std::ifstream inputfile( filename_to_open.c_str() );   //it is the same as the above line
    std::string line;
    while ( getline(inputfile,line) )
        textstream += line + "\n";
} 
std::string Textclass::contents()
{
    return textstream;
}

int main()
{
    Textclass text1("exercise01.cpp") , text2;
    std::cout << text1.contents();
    std::cout << "\t Now the default-constructor created object :" <<std::endl;
    std::cout << text2.contents();
    return 0;
}
