#include <iostream>
#include <stdlib.h>

auto main() -> int
{
    std::cout << "Size of char    is " << sizeof(char)    << std::endl;
    std::cout << "Size of short   is " << sizeof(short)   << std::endl;
    std::cout << "Size of int     is " << sizeof(int)     << std::endl;
    std::cout << "Size of long    is " << sizeof(long)    << std::endl;
    std::cout << "Size of long int is " << sizeof(long int)    << std::endl;
    std::cout << "Size of unsigned long int is " << sizeof(unsigned long int)    << std::endl;
    std::cout << "Size of int32_t is " << sizeof(int32_t) << std::endl;
    std::cout << "Size of int64_t is " << sizeof(int64_t) << std::endl;
    std::cout << "Size of char *  is " << sizeof(char *)  << std::endl;
    std::cout << "Size of float   is " << sizeof(float)   << std::endl;
    std::cout << "Size of double  is " << sizeof(double)  << std::endl;
    return 0;
}
