#include <iostream>
#include <numeric>
#include <limits>
 
int main()
{
    std::cout << "cantidad de digitos que pueden representarse sin redondeos ni desbordamiento :\n";
    std::cout << "float: " << std::numeric_limits<float>::digits10 << " digitos significativos.\n";
    std::cout << "double: " << std::numeric_limits<double>::digits10 << " digitos significativos.\n";
    std::cout << "long double: " << std::numeric_limits<long double>::digits10 << " digitos significativos.\n";
}

