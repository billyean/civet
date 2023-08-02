#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void testRemoveElem() {
    vector<wstring> vs1 = {L"儿", L"嬉", L"漫", L"说", L"重", L"重", L"午"};
    auto iter = remove(vs1.begin(), vs1.end(), L"漫");
    vs1.erase(iter, vs1.end());
    copy(vs1.cbegin(), vs1.cend(), ostream_iterator<wstring, wchar_t>(wcout));
    wcout << endl;

    vs1 = {L"儿", L"嬉", L"漫", L"说", L"重", L"重", L"午"};
    vs1.erase(remove_if(vs1.begin(), vs1.end(), [](wstring elem){
          return elem == L"重";
    }));
    copy(vs1.cbegin(), vs1.cend(), ostream_iterator<wstring, wchar_t>(wcout));
    wcout << endl;

    vs1 = {L"儿", L"嬉", L"漫", L"说", L"重", L"重", L"午"};
    unique(vs1.begin(), vs1.end());
    copy(vs1.cbegin(), vs1.cend(), ostream_iterator<wstring, wchar_t>(wcout));
    wcout << endl;
}

auto main() -> int {
  locale::global(locale(""));
  wcout.imbue(locale(""));
  testRemoveElem();
}
