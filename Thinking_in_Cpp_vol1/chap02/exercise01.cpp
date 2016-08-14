//http://www.drbio.cornell.edu/pl47/programming/TICPP-2nd-ed-Vol-one-html/LaunchContents.html
#include<iostream>
#include<string>
int main()
{
    std::string name;
    int age;
    std::cout << "What is your name? ";
    //std::cin >> name;
    getline(std::cin,name);
    std::cout << "And how old are you (in years)? " ;
    std::cin >> age;
    std::cout << "Hello \"" << name << "\", " << age << " is a nice age!" << std::endl;
    return 0;
}
