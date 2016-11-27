#include <iostream>
#include <string>

class Message 
{
    private: std::string msg;
    public: Message()
             { msg = "Constructor with this string as a default value" ; } 
            Message(std::string constructor_msg) // this is not required in the exercise,but I just did it
             { msg = constructor_msg; } 
            void print() { std::cout << msg << std::endl; }
            void print(std::string external_msg) 
             { std::cout << external_msg ; std::cout << msg << std::endl; }
            // But instead of 2 overloaded functions we can have the following :
            ////(and that is the answer to the question at the end of the exercise)
            //void print(std::string external_msg="") 
             //{ std::cout << external_msg ; std::cout << msg << std::endl; }
};

int main(void) 
{
    std::string message1 = " This is an external message , passed in\n";
    Message msg1 , msg2("Interesting!");
    msg2.print();
    msg1.print(message1);
    return 0;
}
