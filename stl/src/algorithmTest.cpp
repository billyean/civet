#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

void for_eachTest() {
    array<int, 10> ari{1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    for_each(ari.begin(), ari.end(), [&sum](int i) {
        sum += i;
    });
    cout << "sum of ari is " << sum << endl;
}

void minMax() {
  // min_element/max_element return iterator
  vector<string> vs = {"I", "am", "adorable"};
  cout << "min_element of vs is " << *min_element(vs.cbegin(), vs.cend()) << endl;
  cout << "max_element of vs is " << *max_element(vs.cbegin(), vs.cend()) << endl;

  list<int> li{1,2,3,4,5,6,7,8,9,10,11,12,13};
  auto min_max = minmax_element(li.cbegin(), li.cend());
  cout << "min_element/max_element of li is (" << *(min_max.first)  << "/" << *(min_max.second) << ")" << endl;
}

void countTest() {
  deque<char> dc{'H', 'e', 'l', 'l', 'o', ',', 'w', 'o', 'r', 'l', 'd', '!'};
  cout << "l's count of dc is " << count(dc.cbegin(), dc.cend(), 'l') << endl;

  list<int> li{1,2,3,4,5,6,7,8,9,10,11,12,13};
  cout << "4 times's count of dc is " << count_if(li.cbegin(), li.cend(), [](int i) -> bool{
    return (i & 0x03) == 0;
  }) << endl;
}

auto main() -> int {
    for_eachTest();
    minMax();
    countTest();
}
