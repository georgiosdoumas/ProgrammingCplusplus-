// Beginning C++ 2014 , Chapter 05 
// Ex5_13.cpp  Using array<T,N> to create Body Mass Index (BMI) table
// My implementation is based on the book but has various differences
 
#include <iostream>
#include <iomanip>
#include <array>        // needed for the array<T,N>
using std::cout; using std::endl; using std::setw;
 
int main()
{
    const double lbs_per_kg {2.2};
    const double ins_per_m {39.37};
    const unsigned int inches_per_foot {12U};
    const unsigned int min_wt {100U};   // Minimum weight (lb) in table
    const unsigned int max_wt {250U};   // Maximum weight in table
    const unsigned int wt_step {10U};
    const size_t wt_count {1 + (max_wt - min_wt) / wt_step};
    const unsigned int min_ht {48U};  // Minimum height (inches) in table
    const unsigned int max_ht {84U};  // Maximum height in table
    const unsigned int ht_step {2U};
    const size_t ht_count { 1 + (max_ht - min_ht) / ht_step };
    // Create weights from 100lbs to 250, in steps of 10lbs
    std::array<unsigned int, wt_count> weight_lbs {};
    for (size_t i{}, w{ min_wt } ; i < wt_count ; w += wt_step, ++i)
      weight_lbs[i] = w;
    // Create heights from 48 inches to 84, in steps of 2 inches
    std::array<unsigned int, ht_count> height_ins {};
    for (size_t i {}, h{ min_ht } ; h <= max_ht ; h += ht_step) 
      height_ins.at(i++) = h;
    // Output table headings
    cout << "in/lb |";      // leftmost vertical column, followed by the other columns
    for (auto w : weight_lbs) cout << setw(5) << w << " |";
    cout << endl;
    // Output line below headings, for wt_count columns (plus 1, for the leftmost col that will output the inches)
    for (size_t i{1} ; i <= wt_count+1 ; ++i) cout << "-------";
    cout << endl;
    double bmi {};              // Stores BMI
    unsigned int feet {};       // Whole feet for output
    unsigned int inches {};     // Whole inches for output
    for (auto h : height_ins)
    {
        feet = h / inches_per_foot;
        inches = h % inches_per_foot;
        cout << setw(2) << feet << "'" << setw(2) << inches << "\"" << "|";
        cout << std::fixed << std::setprecision(1);
        for (auto w : weight_lbs)
        {  // BMI = weight/(height*height)   ,  weight in kilograms, height in meters
            bmi = (w / lbs_per_kg) / ( (h / ins_per_m) * (h / ins_per_m) );
            cout << setw(2) << " " << bmi << "|";
        }
        cout << endl;
    }
    // Output line below table
    for (size_t i {1} ; i <= wt_count+1 ; ++i)  cout << "-------";
    cout << "\nBMI from 18.5 to 24.9 is normal" << endl;
}
// g++ -Wall -std=c++11 -o example5_13std_arrayBMI example5_13std_arrayBMI.cpp
