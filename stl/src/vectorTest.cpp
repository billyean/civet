#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <cstring>

using namespace std;

void testShrink() {
    std::vector<int> v;
    v.reserve(80);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout <<  "Before shrink " << (v.capacity() == v.size() ? "v.capacity() == v.size()" : "v.capacity() != v.size()" ) << std::endl;
    v.shrink_to_fit();
    std::cout <<  "After shrink " << (v.capacity() == v.size() ? "v.capacity() == v.size()" : "v.capacity() != v.size()" ) << std::endl;
    std::cout << "v.capacity() = " <<  v.capacity() << "; v.size() = " <<  v.size() << std::endl;
    v.push_back(4);
    std::cout <<  "After adding 4 " << (v.capacity() == v.size() ? "v.capacity() == v.size()" : "v.capacity() != v.size()" ) << std::endl;
    std::cout << "v.capacity() = " <<  v.capacity() << "; v.size() = " <<  v.size() << std::endl;
}

void testConstructor() {
    std::vector<std::string> v1{"hello","world","today","is","sunday"};

    std::vector<std::string> v2(v1);
    std::cout << "print elements in v2 : " << std::endl;
    std::copy(v2.cbegin(), v2.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

    std::cout << "v2.capacity() = " <<  v2.capacity() << "; v2.size() = " <<  v2.size() << std::endl;

    std::cout <<  (v1 == v2 ? "v1 == v2" : "v1 != v2") << std::endl;
    std::vector<std::string> v3(v1);
    std::cout <<  (v2 == v3 ? "v2 == v3" : "v2 != v3") << std::endl;
    std::vector<std::string> v4(std::move(v1));
    std::cout <<  (v4 == v2 ? "v4 == v2" : "v4 != v2") << std::endl;
    // Expect != here because move semantic changed v1
    std::vector<std::string> v5 = std::move(v1);
    std::cout <<  (v5 == v2 ? "v5 == v2" : "v5 != v2") << std::endl;

    std::vector<std::string> v6(5);
    v6[0] = "hello";
    v6[1] = "world";
    v6[2] = "today";
    v6.at(3) = "is";
    v6.at(4) = "sunday";

    std::cout << "print elements in v6 : " << std::endl;
    copy(v6.cbegin(), v6.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << "v6.capacity() = " <<  v6.capacity() << "; v6.size() = " <<  v6.size() << std::endl;

    std::cout <<  (v6 == v2 ? "v6 == v2" : "v6 != v2") << std::endl;
}

void testAssignment() {
    std::vector<long> v1{10, 9, 8, 7, 6, 5};
    std::vector<long> v2{1, 2, 3, 4};
    std::vector<long> v3{1, 2, 3, 4};

    // Swap test
    std::cout << "before swap print v1 and v2" << std::endl;

    copy(v1.cbegin(), v1.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    copy(v2.cbegin(), v2.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    v1.swap(v2);

    std::cout << "after swap print v1 and v2" << std::endl;
    copy(v1.cbegin(), v1.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    copy(v2.cbegin(), v2.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;

    // assign test
    v3.assign(2, 12);
    std::cout << "after assign 2 12 ,  v3 :" << std::endl;
    copy(v3.cbegin(), v3.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    v1.assign(v1.begin() + 1, v1.end() - 1);
    std::cout << "after assign v1.begin() + 1, v1.end() - 1,  v1 :" << std::endl;
    copy(v1.cbegin(), v1.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    v3.assign({1,2,3,4});
    std::cout << "after assign a initlist ,  v3 :" << std::endl;
    copy(v3.cbegin(), v3.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
}

void testIterator() {
    std::vector<int> fibonacci{1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    std::cout << "fibonacci:begin() == " << *fibonacci.begin() << std::endl;
    std::cout << "fibonacci:end() == " << *fibonacci.end() << std::endl;
    std::cout << "fibonacci:cbegin() == " << *fibonacci.cbegin() << std::endl;
    std::cout << "fibonacci:cend() == " << *fibonacci.cend() << std::endl;

    // Reverse a vector with assign and r-iterator.
    std::vector<int> tmp;
    tmp.assign(fibonacci.crbegin(), fibonacci.crend());
    swap(fibonacci, tmp);
    std::cout << "after reverse,  fibonacci:" << std::endl;
    copy(fibonacci.cbegin(), fibonacci.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
}

void testInsertOrRemove() {
    std::vector<char> vc{'I', ' ', 'a', 'm', ' ', 'a', 'd', 'o', 'r', 'a', 'b', 'l', 'e', '!', '\0'};
    if (vc.empty()) {
        std::cout << "vc is expected not empty" << std::endl;
    }
    printf("%s\n", &vc[0]);

    vc.pop_back();
    std::cout << "pop_back a character " << std::endl;
    vc.push_back('e');
    std::cout << "push_back a character " << std::endl;

    std::cout << "vc.size() = " << vc.size() << std::endl;
    std::vector<char>::iterator pos = find(vc.begin(), vc.end(), 'a');
    while (pos != vc.end()) {
        vc.erase(pos);
        pos = find(vc.begin(), vc.end(), 'a');
    }
    std::cout << "after remove all 'a', vc.size() = " << vc.size() << std::endl;

    // It plays same function as above:
    std::vector<char>  vc1(vc);
    vc1.erase(remove(vc1.begin(),vc1.end(), 'a'), vc1.end());
    std::cout << "after remove all 'a', vc1.size() = " << vc1.size() << std::endl;

    vc = {'I', ' ', 'a', 'm', ' ', 'a', 'd', 'o', 'r', 'a', 'b', 'l', 'e'};
    vc1.insert(vc1.begin()  +  2, 'a');
    vc1.insert(vc1.begin()  +  5, 'a');
    vc1.insert(vc1.begin()  +  9, 'a');
    std::cout <<  "after add back all 'a' " << (vc1 == vc ? "vc1 == vc" : "vc1 != vc") << std::endl;
    vc1.insert(vc1.begin() + 5, {});
    std::cout <<  "after add a empty list " << (vc1 == vc ? "vc1 == vc" : "vc1 != vc") << std::endl;

    vc1.clear();
    vc1.insert(vc1.end(), 'I');
    vc1.insert(vc1.end(), ' ');
    vc1.insert(vc1.end(), 'a');
    vc1.insert(vc1.end(), 'm');
    vc1.insert(vc1.end(), ' ');
    vc1.insert(vc1.end(), 'a');
    vc1.insert(vc1.end(), 'd');
    vc1.insert(vc1.end(), 'o');
    vc1.insert(vc1.end(), 'r');
    vc1.insert(vc1.end(), 'a');
    vc1.insert(vc1.end(), 'b');
    vc1.insert(vc1.end(), 'l');
    vc1.insert(vc1.end(), 'e');
    std::cout <<  "after clear and insert one by one " << (vc1 == vc ? "vc1 == vc" : "vc1 != vc") << std::endl;

    vc.resize(5);
    std::cout <<  "after resize vc " << (vc1 == vc ? "vc1 == vc" : "vc1 != vc") << std::endl;
}

void testAsArray() {
    std::vector<char> vc;
    vc.resize(30);
    strcpy(vc.data(), "I am adorable!");
    printf("%s\n", vc.data());
    printf("%s\n", &vc[0]);
}

void testSpecializationBoolean() {
    std::vector<bool> bvc{true, true, false, false, false, true, false};
    copy(bvc.cbegin(), bvc.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;

    bvc.flip();
    copy(bvc.cbegin(), bvc.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;

    bvc[2].flip();
    bvc[3].flip();
    bvc[4].flip();
    bvc[6].flip();
    copy(bvc.cbegin(), bvc.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;

    bvc = {true, true, false, false, false, true, false};
    // Reverse bvc
    for (int i = 0, j = bvc.size() - 1; i < j; i++, j--) {
        bool t = bvc[i];
        bvc[i] = bvc[j];
        bvc[j] = t;
    }
    copy(bvc.cbegin(), bvc.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
}

auto main() -> int {
    std::vector<std::string> line_separator;
    line_separator.insert(line_separator.begin(), 80, "=");
    line_separator.insert(line_separator.end(), "\n");
    std::cout << "test testShrink()" << std::endl;
    copy(line_separator.cbegin(), line_separator.cend(), std::ostream_iterator<std::string>(std::cout));
    testShrink();
    std::cout << "test testConstructor()" << std::endl;
    copy(line_separator.cbegin(), line_separator.cend(), std::ostream_iterator<std::string>(std::cout));
    testConstructor();
    std::cout << "test testAssignment()" << std::endl;
    copy(line_separator.cbegin(), line_separator.cend(), std::ostream_iterator<std::string>(std::cout));
    testAssignment();
    std::cout << "test testIterator()" << std::endl;
    copy(line_separator.cbegin(), line_separator.cend(), std::ostream_iterator<std::string>(std::cout));
    testIterator();
    std::cout << "test testInsertOrRemove()" << std::endl;
    copy(line_separator.cbegin(), line_separator.cend(), std::ostream_iterator<std::string>(std::cout));
    testInsertOrRemove();
    std::cout << "test testAsArray()" << std::endl;
    copy(line_separator.cbegin(), line_separator.cend(), std::ostream_iterator<std::string>(std::cout));
    testAsArray();
    std::cout << "test testSpecializationBoolean()" << std::endl;
    copy(line_separator.cbegin(), line_separator.cend(), std::ostream_iterator<std::string>(std::cout));
    testSpecializationBoolean();
}
