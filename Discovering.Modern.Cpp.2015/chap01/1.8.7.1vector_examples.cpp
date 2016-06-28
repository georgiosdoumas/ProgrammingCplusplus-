#include <iostream>
#include <vector>
#include <cassert>
void vector_add(const std::vector<float>& v1, const std::vector<float>& v2, std::vector<float>& s)
{
    assert(v1.size() == v2.size());
    assert(v1.size() == s.size());
    for (unsigned i= 0; i < v1.size(); ++i)
        s[i]= v1[i] + v2[i];
}
//another way to implement the function is :
std::vector<float> add(const std::vector<float>& v1, const std::vector<float>& v2)
{
    assert(v1.size() == v2.size());
    std::vector<float> s(v1.size());  //result vector of sum
    for (unsigned i= 0; i < v1.size(); ++i)  s[i]= v1[i] + v2[i];
    return s;
}
int main ()
{
    std::vector<float> v= {1, 2, 3}, w= {7, 8, 9},s(3) ;
    vector_add (v, w , s);
    for (unsigned i=0; i<s.size(); i++) std::cout << s[i] << " " ;
    std::cout << std::endl;
    std::vector<float> v1= {-1, -2, -3}, w1= {-7, -8, -9},s1=add(v1,w1) ;
    for (unsigned i=0; i<s1.size(); i++) std::cout << s1[i] << " " ;
    return 0;
}
