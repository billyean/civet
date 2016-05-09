#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<string> sentences;
    sentences.reserve(5);

    sentences.push_back("Hello, ");
    sentences.insert(sentences.end(), {"how", "are", "you", "doing", "?"});

    copy(sentences.cbegin(), sentences.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << " max_size(): " << sentences.max_size() << endl;
    cout << " size(): " << sentences.size() << endl;
    cout << " capacity(): " << sentences.capacity() << endl;
    swap(sentences[1], sentences[3]);
    sentences.insert(find(sentences.begin(), sentences.end(), "?"), "always");
    sentences.back() = "!";
    copy(sentences.cbegin(), sentences.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;
    cout << " size(): " << sentences.size() << endl;
    cout << " capacity(): " << sentences.capacity() << endl;

    sentences.pop_back();
    sentences.pop_back();
    sentences.shrink_to_fit();
    cout << " size(): " << sentences.size() << endl;
    cout << " capacity(): " << sentences.capacity() << endl;
}
