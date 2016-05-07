#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
void printList1 (std::initializer_list<T> vals)
{
  for (auto p=vals.begin(); p!=vals.end(); ++p) { // process a list of values
    std::cout << *p << "\n";
  }
}

template <typename T>
void printList2 (std::initializer_list<T> vals)
{
  for (auto p : vals) { // process a list of values
    std::cout << p << "\n";
  }
}

template <typename T>
void switchElements (std::vector<T>& vals)
{
  T temp = vals[0];
  vals[0] = vals[2];
  vals[2] = temp;  
}

void multiply3 (std::vector<int>& vals)
{
  for (auto& elem : vals) {  // process a list of values
    elem *= 3;
  }
}

template <typename T>
void printElements (T& vals)
{
  for (const auto& elem : vals) { // process a list of values
    std::cout << elem << "\n";
  }
}

auto main() -> int
{
  std::vector<int> v{1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
  //multiply3(v);
  //printElements(v);
  //const std::vector<int> v2{1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
  switchElements(v);
  printElements(v);
  return 0;
}
