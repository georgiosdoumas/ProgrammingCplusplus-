//I expanded the example given in the book,with one more category of fruits , dry fruits.

#include <iostream>
#include <ctype.h>
#define NELEMS(A) (sizeof(A) / sizeof(A[0]))   //number of elements : size of whole array / size of first element
using namespace std;
int main()
{
    // lets define 2 arrays of pointers-to-char,with fruit names
    const char *domestic[] = { "avocado", "figs", "lemons","oranges", "strawberries", "watermelon"};      
    const char *tropical[] = {"bananas", "coconuts", "guava","kiwi", "mangos", "papayas"};
    enum FruitType { Domestic, Tropical, Dry, NoFruit };   // a possible change in the future to accomodate one more category...
    const char *dry[] = { "raisins", "figs" };          //....with these elements 
    const char **fruits[] = { domestic, tropical ,dry };    // array of pointers to pointers for the 3 category cases
    const int NumFruits = NELEMS(domestic) + NELEMS(tropical) + NELEMS(dry) ; 
   int nf;
   cout << "NumFruits = " << NumFruits << endl;
   for (int ft = Domestic; ft < NoFruit; ft++) //iterate through the 3 enumerated values: Domestic,Tropical,Dry
   {
      switch (ft) 
      {
         case Domestic: cout << "domestic:" << endl;
              nf = NELEMS(domestic);
              break;
         case Tropical: cout << "tropical:" << endl;
              nf = NELEMS(tropical);
              break;
         case Dry: cout << "dry fruits:" << endl;
              nf = NELEMS(dry);
              break;
      }
      for (int i = 0; i < nf; i++)
        cout << '\t' << static_cast<char>(toupper(*fruits[ft][i])) << " for " << *(fruits[ft] + i) << endl;
   }
   return 0;
}
