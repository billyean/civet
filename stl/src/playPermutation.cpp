#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printPermutate(vector<int> &v) {
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    while (next_permutation(v.begin(), v.end())) {
        copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

auto main() -> int {
    vector<int> v1{1,2,3};
    vector<int> v2{1,1, 2,3};
    printPermutate(v1);
    cout << "------" << endl;
    printPermutate(v2);
}
