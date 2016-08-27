    #include <iostream>
    using namespace std;

    int dog, cat, bird, fish;
    char c1, c2 , c3 ; //try it with 2 , 3 , 4  and 5 char variables to see that the position of next double is the same
    double d1 , d2 ;

    void fint(int pet) {
      cout << "pet id number: " << pet << endl;
    }
    void fdouble(double pet) {
      cout << "pet id number: " << pet << endl;
    }    

    int main() 
    {
      int i, j, k;
      cout << "Local variables of main() ,  on the stack  : \n" ;
      cout << "i: " << (long)&i << endl; // 4 bytes each
      cout << "j: " << (long)&j << endl;
      cout << "k: " << (long)&k << endl;
      cout << "Global variables , on the stack : \n" ;
      cout << "fint(): " << (long)&fint << endl; //the compiler does not let me have sizeof(fint)
      cout << "fdouble(): " << (long)&fdouble << endl;
      cout << "dog: " << (long)&dog << endl; // 4 bytes each
      cout << "cat: " << (long)&cat << endl;
      cout << "bird: " << (long)&bird << endl;
      cout << "fish: " << (long)&fish << endl;
      cout << "c1 : " << (long)&c1 << endl;  // 1 byte 
      cout << "c2 : " << (long)&c2 << endl;
      cout << "c3 : " << (long)&c3 << endl;  
      cout << "d1 : " << (long)&d1 << endl;  // 8 bytes
      cout << "d2 : " << (long)&d2 << endl;
    } 
