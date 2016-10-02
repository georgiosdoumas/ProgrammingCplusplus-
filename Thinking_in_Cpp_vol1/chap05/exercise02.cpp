#include <iostream>

class Libc //either only this class or only the next will be used
{
    private: std::string t,c,w;  //title , category , writer
    public: 
        void set_t(std::string word) { t = word; }
        std::string get_t() { return t; } 
        void set_c(std::string word) { c = word; }
        std::string get_c() { return c; }      
        void set_w(std::string word) { w = word; }
        std::string get_w() { return w; }
}; 

class Libc_arr 
{
    private: std::string b[3];
    public: 
        void set_t(std::string word) { b[0] = word; } //title
        std::string get_t() { return b[0]; } 
        void set_c(std::string word) { b[1] = word; } //category 
        std::string get_c() { return b[1]; }      
        void set_w(std::string word) { b[2] = word; } //writer
        std::string get_w() { return b[2]; }
};                
int main()  // I think that what the exercise wants us to realize is this : 
{
    Libc b;  //comment out this line and un-comment the next to see that a change in implementation doesn't break the code in main()
    // Libc_arr b; //Suppose we decided to change the implementation of the class,the rest lines do not have to change 
    b.set_t("Thinking in C++");
    b.set_c("Programming");
    b.set_w("Bruce Eckel");
    std::cout << b.get_t() << std::endl;
    std::cout << b.get_c() << std::endl;
    std::cout << b.get_w() << std::endl;
    return 0;
}
