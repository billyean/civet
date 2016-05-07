#include <iostream>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer pointer, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        printf(" %.2x", pointer[i]);
    }
    printf("\n");
}

void printEndian() 
{
    int a = 0x12345678;
    byte_pointer ap = (byte_pointer) &a;
    show_bytes(ap, 1);
    show_bytes(ap, 2);
    show_bytes(ap, 3);
}

void printString() 
{
    const char *m= "mnopqr";
    show_bytes((byte_pointer)m, strlen(m));
}

union byteint
{
    unsigned char b[sizeof(int)];
    int i;
};

auto main() -> int
{
    byteint bi;
    bi.i = 0x01020304;
    // Most Intel-compatible machines operate in little-endian mode.
    // Most machines from IBM, Oracle operate in big-endian mode.
    if (bi.b[0] == 0x01)
        std::cout << "Big endian" << std::endl;
    else 
        std::cout << "Little endian" << std::endl;
    printEndian();
    printString();
}
