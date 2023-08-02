#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

void testReverse() {
    list<float> li{3.14159, 2.71828, 1.61803};
    reverse(li.begin(), li.end());
    copy(li.cbegin(), li.cend(), ostream_iterator<float>(cout, " "));
    cout << endl;
    copy(li.rbegin(), li.rend(), ostream_iterator<float>(cout, " "));
    cout << endl;
}

void printPermutate(vector<int> &v) {
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    while (next_permutation(v.begin(), v.end())) {
        copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

auto main() -> int {
    testReverse();

    vector<int> v1{1,2,3};
    vector<int> v2{1,1, 2,3};
    printPermutate(v1);
    cout << "------" << endl;
    printPermutate(v2);
}
