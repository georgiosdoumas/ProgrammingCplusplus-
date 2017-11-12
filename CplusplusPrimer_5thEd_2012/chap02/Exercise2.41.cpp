/* Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22),
§ 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your Sales_data class in
the same file as your main function.
*/
#include<iostream>
#include <string>
struct Sales_data {
    std::string bookISBN;
    std::string bookTitle;
    unsigned units_sold = 0;  
    // unsigned units_sold; /* in case you want to compile with pre c++11 , do not initialize */
    double revenue = 0.0;     
    // double revenue ; /* in case you want to compile with pre c++11 , do not initialize */
};
// This is implementation of what exercise 1.20 asks. Exercise 1.22 will be solved in Exercise2.42
int main() 
{
    Sales_data mybook;
    std::cout << "  ISBN      " << "  Title         " << " Items sold " << "  Total revenue $ " << std::endl;
    // read ISBN, number of copies sold, and sales price
    while (std::cin >> mybook.bookISBN >> mybook.bookTitle >> mybook.units_sold >> mybook.revenue) 
    // write ISBN, title of book, number of copies sold, total revenue of these number of copies sold
      std::cout << mybook.bookISBN <<" "<< mybook.bookTitle <<" "<< mybook.units_sold <<" "<< mybook.revenue << std::endl;
	return 0;
}
// g++ -Wall -std=c++11 -o Exercise2.41 Exercise2.41.cpp 
// ./Exercise2.41 < Sales_data_info.txt 

/* Contents of file Sales_data_info.txt , where the title is a single word (no spaces, very primitive implementation for Title!) 
0-201-70353-X Programming 4 24.99
0-201-82470-1 Data_Structures 4 45.39
0-201-88954-4 Design 2 15.00 
0-201-88954-4 Networks 5 12.00
*/ 
