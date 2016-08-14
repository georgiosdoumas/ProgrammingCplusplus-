#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<float> v1,v2, vresult;
    for(int i=0;i<10;i++) 
    { v1.push_back(i+1) ; v2.push_back(2*i+1); }
    for(int j=0;j<v1.size();j++) 
    { vresult.push_back(v1[j]+v2[j]); cout << vresult[j] << endl; }
    return 0;
}
