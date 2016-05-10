#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> vi;
    unordered_map<int, int> vm;

    for_each(nums.cbegin(), nums.cend(), [&vm](int n) {
        auto f = vm.find(n);
        if (f == vm.end()) {
            vm.insert({n, 1});
        } else {
            (*f).second++;
        }
     });
     vector<pair<int, int>> vp(vm.cbegin(), vm.cend());
     sort(vp.begin(), vp.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool {
        return p1.second > p2.second;
     });
     for_each(vp.cbegin(), vp.cbegin() + k, [&vi](pair<int, int> p){
        vi.push_back(p.first);
     });
     return vi;
}

auto main() -> int {
    std::vector<int> sample{1,1,1,2,2,3};
    auto topN = topKFrequent(sample, 2);
    std::for_each(topN.cbegin(), topN.cend(), [](int i) {
        std::cout << i << std::endl;
    });
}
