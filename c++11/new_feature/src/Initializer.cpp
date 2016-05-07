#include <iostream>

void print (std::initializer_list<int> list)
{
    // New for-loop in C++ 11.
    for (auto i : list) {
        std::cout << i << std::endl;
    }
}

class P_Initializer {
public:
    P_Initializer(int, int);
    P_Initializer(std::initializer_list<int>);
};

P_Initializer::P_Initializer(int i1, int i2) {
    std::cout << "Calling P_Initializer(int, int)" << std::endl;
}

P_Initializer::P_Initializer(std::initializer_list<int> list) {
    std::cout << "Calling P_Initializer(std::initializer_list<int>)" << std::endl;
}

auto main() -> int
{
    // New auto keyword in C++ 11
    auto list = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
    print(list);

    P_Initializer p(3, 5);
    P_Initializer q{3, 5};
    P_Initializer r{3, 5, 42};
    P_Initializer s = list;


}
