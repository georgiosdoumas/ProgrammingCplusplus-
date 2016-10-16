//: :require.h
// Test for error conditions in programs (no need for using namespace std; )
#ifndef REQUIRE_H
#define REQUIRE_H
#include <cstdio>
#include <cstdlib>
#include <fstream>
inline void require(bool requirement, const char* msg = "Requirement failed") 
{
    if (!requirement) 
    {
        fputs(msg, stderr);
        fputs("\n", stderr);
        exit(1);
    }
}
inline void requireArgs(int argc, int args, const char* msg = "Must use %d arguments") 
{
    if (argc != args + 1)
     {
        fprintf(stderr, msg, args);
        fputs("\n", stderr);
        exit(1);
     }
}
inline void requireMinArgs(int argc, int minArgs,const char* msg ="Must use at least %d arguments") 
{
    if(argc < minArgs + 1) 
    {
        fprintf(stderr, msg, minArgs);
        fputs("\n", stderr);
        exit(1);
    }
}
inline void assure(std::ifstream& in, const char* filename = "") 
{
    if(!in) 
    {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }
}
inline void assure(std::ofstream& in, const char* filename = "") 
{
    if(!in) 
    {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }
}
#endif // REQUIRE_H 
