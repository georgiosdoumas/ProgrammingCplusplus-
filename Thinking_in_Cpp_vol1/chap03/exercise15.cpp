#include<iostream>
#include <string>
struct GlobalItem //it could also be defined into main.The exercise is really simple, just for practicing the notations.
{
    std::string name , type ; 
    int amount;
};
typedef struct GlobalItem gitem;  //not much point for this now, only doing it per exercise requirements.
int main()
{
    gitem pc;  //if the line typedef ... was absent , we should use either of the following lines:
    //GlobalItem pc;  //or:
    // struct GlobalItem pc;   they are both accepted in g++ version 4.8
    std::cout << "gitem size (before initialization): " << sizeof(pc) << std::endl;
    pc.name="lenovo";
    pc.type="desktop pc";
    pc.amount = 23;
    std::cout << "gitem size (after initialization): " << sizeof(pc) << std::endl;
    std::cout << pc.name << " " << pc.type << ", available in " << pc.amount << " pieces." << std::endl;
    gitem* pgitem=&pc;
    pgitem->name="Dell";
    pgitem->type="laptop";
    pgitem->amount=12;
    std::cout << "After changes : " << std::endl;
    std::cout << pc.name << " " << pc.type << ", available in " << pc.amount << " pieces." << std::endl;
    return 0;
}
