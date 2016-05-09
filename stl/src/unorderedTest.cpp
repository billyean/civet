#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void testConstructor() {
    // First test unordered_set.
    unordered_set<int> us1{1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    // Assume this should be 10.
    cout << us1.size() << endl;

    // Note hash function only calculate hash code, but it won't duplicate
    // elements.
    auto hs = [](const int&  i) -> int {
        // cout << (i & 0x03) << endl;
        return i & 0x03;
    };
    unordered_set<int, decltype(hs)> us2(10, hs);
    us2 = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    // Assume this should be 10.
    cout << us2.size() << endl;

    // compare function doesn't make duplicate elements
    auto hscmp = [](const int&  i1, const int&  i2) -> bool {
        return ((i1 & 0x03) == (i2 & 0x03));
    };
    unordered_set<int, decltype(hs), decltype(hscmp)> us3(10, hs, hscmp);
    us3 = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    // Assume this should be 10.
    cout << us3.size() << endl;

    unordered_multiset<int> us4{1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    // Assume this should be 11.
    cout << us4.size() << endl;


    unordered_multiset<int, decltype(hs), decltype(hscmp)> us5(10, hs, hscmp);
    us5 = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    // Assume this should be 10.
    cout << us5.size() << endl;

    // First test unordered_map, except map has key, value pair, others should
    // be same.
    unordered_map<string, int> um1{{"today", 1}, {"is", 2}, {"mother's", 3}, {"day", 4}};
    cout << um1.size() << endl;

    // Note hash function only calculate hash code, but it won't duplicate
    // elements.
    auto hm = [](const string&  s) -> int {
        // cout << (i & 0x03) << endl;
        return s[s.length() - 1];
    };
    unordered_map<string, int, decltype(hm)> um2(10, hm);
    um2 = {{"today", 1}, {"is", 2}, {"mother's", 3}, {"day", 4}};
    cout << um2.size() << endl;

    // compare function doesn't make duplicate elements
    auto hmcmp = [](const string&  s1, const string&  s2) -> bool {
        // cout << (i & 0x03) << endl;
        return s1[s1.length() - 1] == s2[s2.length() - 1];
    };
    unordered_map<string, int, decltype(hm), decltype(hmcmp)> um3(10, hm, hmcmp);
    um3 = {{"today", 1}, {"is", 2}, {"mother's", 3}, {"day", 4}};
    cout << um3.size() << endl;
}

auto main() -> int {
    std::vector<std::string> line_separator;
    line_separator.insert(line_separator.begin(), 80, "=");
    line_separator.insert(line_separator.end(), "\n");
    std::cout << "test testConstructor()" << std::endl;
    copy(line_separator.cbegin(), line_separator.cend(), std::ostream_iterator<std::string>(std::cout));
    testConstructor();
}
