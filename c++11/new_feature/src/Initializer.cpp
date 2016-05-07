#include <iostream>
#include <vector>

void print (std::vector<int>& vector)
{
    // New for-loop in C++ 11.
    for (auto v : vector) {
        std::cout << v << std::endl;
    }
}

// In C++ 11, lambda's type is std::function<returnType<ParamType1,ParamType2,...>>
void manipulate (std::vector<int> &vec, std::function<int(int)> lambda)
{
    // Manipulate with element by refernece.
    for (auto& elem : vec) {
        elem = lambda(elem);
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
    std::vector<int> vec{1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};
    manipulate(vec, [](int i) -> int { return i << 1; });
    print(vec);

    P_Initializer p(3, 5);
    P_Initializer q{3, 5};
    P_Initializer r{3, 5, 42};
    P_Initializer s = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};


}
