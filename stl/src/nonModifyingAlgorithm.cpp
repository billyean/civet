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

void findTest() {
  // Expect find word "the" but not find word "again"
  vector<string> vs{"searches", "for", "the", "first", "element", "with", "the", "passed", "value"};
  auto theWord = find(vs.cbegin(), vs.cend(), "the");
  while (theWord != vs.cend()) {
      cout << "Find word " << *theWord << endl;
      theWord = find(++theWord, vs.cend(), "the");
  }
  auto againWord = find(vs.cbegin(), vs.cend(), "again");
  while (againWord != vs.cend()) {
      cout << "Find word " << *againWord << endl;
      againWord = find(++againWord, vs.cend(), "again");
  }

  // find_if and find_if_not test
  list<string> ls{"searches", "for", "the", "first", "element", "that", "matches", "a", "criterion"};
  auto sendWord = find_if(ls.cbegin(), ls.cend(), [](string s) {
      return s[s.length() - 1] == 's';
  });
  while (sendWord != ls.cend()) {
      cout << "Find s end word " << *sendWord << endl;
      sendWord = find_if(++sendWord, ls.cend(), [](string s) {
          return s[s.size() - 1] == 's';
      });
  }

  auto nsendWord = find_if_not(ls.cbegin(), ls.cend(), [](string s) {
      return s[s.length() - 1] == 's';
  });
  while (nsendWord != ls.cend()) {
      cout << "Find not s end word " << *nsendWord << endl;
      nsendWord = find_if_not(++nsendWord, ls.cend(), [](string s) {
          return s[s.size() - 1] == 's';
      });
  }
}

void ofTest() {
    list<int> li{1,2,3,4,5,6,7,8,9,10,11,12,13};
    cout << (all_of(li.cbegin(), li.cend(), [](int i) {
        return i > 0;
    }) ? "All elements in li are greater than 0" : "Not all elements in li are greater than 0") << endl;
    cout << (all_of(li.cbegin(), li.cend(), [](int i) {
        return (i & 0x01) == 0x01;
    }) ? "All elements in li are odd number" : "Not all elements in li are odd number") << endl;

    cout << (any_of(li.cbegin(), li.cend(), [](int i) {
        return i < 0;
    }) ? "There is at least one negative number in li" : "There is no negative number in li") << endl;
    cout << (any_of(li.cbegin(), li.cend(), [](int i) {
        return (i & 0x01) == 0x01;
    }) ? "There is at least one odd number in li" : "There is no odd number in li") << endl;

    cout << (none_of(li.cbegin(), li.cend(), [](int i) {
        return i % 17 == 0;
    }) ? "There is no number in li that is times to 17" : "There is at least one number in li that is times to 17") << endl;
    cout << (none_of(li.cbegin(), li.cend(), [](int i) {
        return i % 5 == 0;
    }) ? "There is no number in li that is times to 5" : "There is at least one number in li that is times to 5") << endl;
}

auto main() -> int {
    for_eachTest();
    minMax();
    countTest();
    findTest();
    ofTest();
}
