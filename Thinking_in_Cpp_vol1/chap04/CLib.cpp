//: C04:CLib.cpp {O} Implementation of example C-like library
// Declare structure and functions:
#include "CLib.h"
#include <iostream>
#include <cassert> 
using namespace std;
const int increment = 40;  // Quantity of elements to add when increasing storage
void initialize(CStash* s, const int sz) 
{
   cout << "\t Initializing an empty stash!" << endl;
  s->element_size = sz;
  s->quantity = 0;
  s->storage = 0;
  s->next_empty = 0;
}
int add(CStash* s, const void* inpelement) 
{
  if(s->next_empty >= s->quantity) inflate(s, increment); //Not enough space left?Expand stash to the predifened value:increment 
  int startBytes = s->next_empty * s->element_size; // Copy element into storage, starting at next empty space.1)byte to start from
  unsigned char* e = (unsigned char*)inpelement;    //2)converting input element to correct pointer form
  for(int i = 0; i < s->element_size; i++)  s->storage[startBytes + i] = e[i]; //3) do the actuall copy, byte by byte
  s->next_empty++;
  return(s->next_empty - 1); // Index number of final element
}
void* fetch(CStash* s, const int index)
{
  assert(0 <= index);  // Check index boundaries: index can not be a negative integer!
  if(index >= s->next_empty)  return 0; //Is the position indicated by index out of boundaries of populated elements? then fetch a 0
  return &(s->storage[index * s->element_size]);  // else return a pointer to desired element
}
int count(CStash* s) 
 { return s->next_empty; }  // Number of elements in CStash
void inflate(CStash* s, const int additional)
{
  assert(additional > 0);
  cout << "\t Expanding stash by " << additional << " number of elements." << endl;
  int oldBytes = s->quantity * s->element_size; //Initial number of bytes , before expansion/inflation
  int newQuantity = s->quantity + additional;  // add additional number of elements ...
  int newBytes = newQuantity * s->element_size; //... and calculate relevant number of bytes
  unsigned char* b = new unsigned char[newBytes];  //allocate memory on the heap for enough bytes 
  for(int i = 0; i < oldBytes; i++)  b[i] = s->storage[i]; // Copy old to new , byte-by-byte
  delete [](s->storage); // Free old storage
  s->storage = b; // Point to new memory
  s->quantity = newQuantity;
}
void cleanup(CStash* s) 
{
  if(s->storage != 0) { cout << "\t freeing storage" << endl; delete []s->storage; }
}
