#include <iostream>
#include <string>
void func_pointer_str(std::string * input)
{
    std::string prefix = "pointer_";
    *input = prefix + *input;   
}
void func_ref_str(std::string & input)
{
    std::string postfix = "_reference";
    input = input + postfix;  
}
int main()
{
    std::string userinput;
    std::cout << "Enter a word " ;
    std::cin >> userinput;
    func_pointer_str(&userinput);
    std::cout << userinput << std::endl;
    func_ref_str(userinput);
    std::cout << userinput << std::endl;    
    return 0;
}
