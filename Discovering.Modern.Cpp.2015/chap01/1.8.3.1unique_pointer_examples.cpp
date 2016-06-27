#include <iostream>
#include <memory>
int main()
{
    double z,y;
    std::unique_ptr<double> dp{new double};
    *dp= 7;
    //dp=&z;  // compilation error
    z=*dp;
    std::cout << z << std::endl;  //outputs 7, all good here.

    double d;
    std::unique_ptr<double> dd{&d};  //compiles , but it is BAD
    *dd=3.7;
    std::cout << d << std::endl;  //I get the value 3.7 in the output,
    // I also get the next statements outputs
    // and at the end I see an error message telling about
    // free(): invalid pointer: 0xsomememoryaddress
    std::cout << "One more thing!" << std::endl;
    double* traditional_dp= dp.get();
    traditional_dp = &y;
    *traditional_dp = 12.1;
    std::cout << y << std::endl;   // outputs 12.1
    //std::unique_ptr<double> dp2{dp};   // compilation error
    std::unique_ptr<double> dpg{dp.get()};  // but this is accepted,dp2 points where dp points
    std::cout << *dpg << std::endl;     // so this outputs 7
    std::unique_ptr<double> dp2{move(dp)}, dp3;
    dp3= move(dp2);
    std::cout << *dp3 << std::endl;     // also this outputs 7
    std::cout //<< *dp << " "    //all these are nullptr now, after the move
              //<< *dd << " "    // so by trying to output their contents , we get segmentation fault
              //<< *traditional_dp << " "
              //<< *dpg << " "
              //<< *dp2 << " "
              << *dp3 << std::endl;    // ths still outputs 7 , and then I get the error message about free() ....
    return 0;
}
