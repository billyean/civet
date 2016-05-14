#include <iostream>
#include <cstdlib>

using namespace std;

class MyString : public string {
  string instance;
public:
    MyString(string s) : instance(s) {}
    MyString& operator+(int i)
    {
      instance +=  to_string(i);
      return *this;
    }
    friend ostream& operator<<(ostream& , const MyString&);
};

// Override << for MyString class
ostream& operator<<(ostream& os, const MyString& ms) {
    os << ms.instance;
    return os;
}

// We couldn't do this decltype(x + y) before C++ 11.
template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y) {
    return x + y;
}

auto main() -> int {
    MyString hs{"hello"};
    auto appendIntToStr = add(hs, 9);
    cout << appendIntToStr << endl;

    auto appendIntToDouble= add(2.3, 9);
    cout << appendIntToDouble << endl;
}
