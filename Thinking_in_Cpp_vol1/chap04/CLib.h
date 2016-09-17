//: C04:CLib.h Header file for a C-like library
// An array-like entity created at runtime. I used keyword const in some places
// to indicate that the passed argument must not be changed in the function
// although this would be strictly needed only when pointers are passed in functions.
// I also changed the names of variables , and added extra comments.

typedef struct CStashTag 
{
  int element_size;      // Size , in bytes, of each space
  int quantity;  // Number of storage spaces that are actually populated by an element
  int next_empty;      // Next empty space
  // Dynamically allocated array of bytes:
  unsigned char* storage;
} CStash;

void initialize(CStash* s, const int element_size);
void cleanup(CStash* s);
int add(CStash* s, const void* element);
void* fetch(CStash* s, const int index);
int count(CStash* s);
void inflate(CStash* s, const int increase);
