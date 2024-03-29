// The efficient Janitor problem. 
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector; using std::cout; using std::endl;

int garbageCollector(vector<float> loads) {
    const float maxWeight = 3.00;
    int number_of_trips = 0;
    if(loads.size() == 0)
        return number_of_trips;
    sort(loads.begin(), loads.end());
    int start = 0, end = loads.size();
    while(start < end) {
        end--;  //for sure the janitor will pick the heaviest element
        number_of_trips++;  // but possibly in the same trip ...
        if((loads[start] + loads[end]) <=  maxWeight)  // ... he might be able to carry also one of the light elements
            start++;
    }
    return number_of_trips;
}

// passing the maximum load for 1 trip as parameter, and using iterators instead of index
int garbageCollector(vector<float> loads, const float maxWeight) {
    int number_of_trips = 0;
    if(loads.size() == 0)
        return number_of_trips;
    sort(loads.begin(), loads.end());
    vector<float>::iterator iter = loads.begin(), stopiter = loads.end();
    while(iter != stopiter) {
        --stopiter;
        number_of_trips++;
        if( (*iter + *stopiter) <= maxWeight ) 
            iter++;
    }
    return number_of_trips;
}


int main()
{
    vector<float> v = {1.99, 1.01, 2.5, 1.5, 1.01};
    int trips = garbageCollector(v);
    cout<<trips<<endl;
    trips = garbageCollector(v, 3.0);
    cout<<trips<<endl;
    return 0;
}
