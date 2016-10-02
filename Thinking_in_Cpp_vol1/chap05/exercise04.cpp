#include <iostream>
class Empire ;
class Emperor ; 
class Empire 
{
    private: std::string name ; //name of empire
             std::string ruler; //name of emperor
    public:
       void set_name(std::string input) { name = input; } 
       std::string get_name() {return name; }
       void set_ruler(Emperor* pking); 
       std::string get_ruler(); 
};
class Emperor
{
    private: std::string name ; //name of emperor. Keyword name here is not confused with "name" of the other class. No need to use other keyword.
             std::string empire; //If I had used "class empire" another keyword like kingdom should go here. But now this string is not confused with class Empire
    public: 
        void set_name(std::string input) { name = input; } 
        std::string get_name() {return name; }
        void set_empire(Empire* pkingdom) ;
        std::string get_empire() ;
};

void Empire::set_ruler(Emperor* pking) { ruler = pking->get_name(); }
std::string Empire::get_ruler() { return ruler; }

void Emperor::set_empire(Empire* pkingdom) { empire = pkingdom->get_name(); }
std::string Emperor::get_empire() { return empire; }
        
int main()
{
    Empire GreekEmpire;
    Emperor GreekKing;
    GreekKing.set_name("Alexander of Philipp");
    GreekEmpire.set_name("Macedonian Kingdom");
    GreekEmpire.set_ruler(&GreekKing);
    GreekKing.set_empire(&GreekEmpire);
    std::cout << GreekEmpire.get_name() << std::endl;
    std::cout << GreekEmpire.get_ruler() << std::endl;
    std::cout << GreekKing.get_name() << " is king of the Greek empire " << GreekKing.get_empire() << std::endl;
    return 0;
}
