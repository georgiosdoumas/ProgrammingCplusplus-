//A very basic program, without using for loops , since on chapter01 they have not been presented yet.
#include <iostream>
#include <cmath>
int main()
{
    std::cout << "3D vectors\n";
    double vector3d_a[3],vector3d_b[3]={1.0,2.0,3.5};
    //vector3d_a[3]={2.0,3.0,4.5};  //wrong! we have to do it element-by-element now:
    vector3d_a[0]=2.0;
    vector3d_a[1]=3.0;
    vector3d_a[2]=4.5;
    double scalarprod=vector3d_a[0]*vector3d_b[0]+vector3d_a[1]*vector3d_b[1]+vector3d_a[2]*vector3d_b[2];
    std::cout << "The scalar product of the 2 vectors is "
              << scalarprod
              << " and the distance between the 2 points (Eucledean norm) is "
              << sqrt(scalarprod);
    return 0;
}
