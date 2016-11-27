//: C07:Stash3.cpp {O}
// Function overloading
#include "exercise06_Stash.h"
#include "../require.h"
#include <iostream>
#include <cassert>
using namespace std;
const int increment = 40;

void Stash::inflate(int increase) 
{
  assert(increase >= 0);
  if(increase == 0) return;
  int oldBytes = quantity * size;
  int newQuantity = quantity + increase;
  int newBytes = newQuantity * size;
  unsigned char* b = new unsigned char[newBytes];
  for(int i = 0; i < oldBytes; i++)  b[i] = storage[i]; // Copy old to new
  delete [](storage); // Release old storage
  storage = b; // Point to new memory
  quantity = newQuantity; // Adjust the size
}

Stash::Stash(int sz, int initQuantity) //implementing the Constructor with the default values
{
  size = sz;
  quantity = 0;
  next = 0;
  storage = 0;
  inflate(initQuantity);
}

Stash::~Stash() 
{
  if(storage != 0) {
    cout << "freeing storage" << endl;
    delete []storage;
  }
}

int Stash::add(void* element) {
  if(next >= quantity) // Not enough space left? then expand by calling inflate(int)
    inflate(increment);
  // Copy element into storage, starting at next empty space:
  int startBytes = next * size;
  unsigned char* e = (unsigned char*)element;
  for(int i = 0; i < size; i++)  storage[startBytes + i] = e[i];
  next++;
  return(next - 1); // Index number
}

void* Stash::fetch(int index) 
{
  require(0 <= index, "Stash::fetch (-)index");
  if(index >= next) return 0; // To indicate the end
  return &(storage[index * size]);      // Produce pointer to desired element:
}

int Stash::count() 
{  return next; } // Number of elements in CStash
