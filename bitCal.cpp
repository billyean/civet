#include <iostream>

int main()
{
    unsigned char a = 0b01001110;
    unsigned char b = 0b11100001;
    std::cout << ((unsigned char)(~a) == 0b10110001) << std::endl;
    std::cout << ((unsigned char)(~b) == 0b00011110) << std::endl;
    std::cout << ((a & b) == 0b01000000) << std::endl;
    std::cout << ((a | b) == 0b11101111) << std::endl;
    std::cout << ((a ^ b) == 0b10101111) << std::endl;
    return 0;
}
