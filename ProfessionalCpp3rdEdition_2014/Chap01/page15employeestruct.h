// Professional C++ 3rd Ed , Chap 01 page 15 header file with struct definition
#ifndef EmployeeStruct_h  //we just need a name to serve as a tag. I chose EmployeeStruct_h, could be something else, but no .h
#define EmployeeStruct_h
struct Employee {
    char firstInitial;
    char lastInitial;
    int employeeNumber;
    float salary;
};
#endif
// header file to be included in page15structEmployee.cpp
