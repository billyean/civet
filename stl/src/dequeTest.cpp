#include <deque>
#include <iostream>
#include <cstdio>
#include <cstdlib>

void testShrink() {
    std::deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(0);
    std::cout <<  "Before shrink d.size() = " << d.size() << std::endl;
    d.shrink_to_fit();
    std::cout <<  "After shrink d.size() = " << d.size() << std::endl;
    d.push_back(4);
    d.push_front(-1);
    std::cout <<  "After adding 4 and -1 d.size() = " << d.size() << std::endl;
}

void testConstructor() {
    std::deque<std::string> d1{"hello","world","today","is","sunday"};

    std::deque<std::string> d2(d1);
    std::cout << "print elements in d2 : " << std::endl;
    copy(d2.cbegin(), d2.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

    std::cout << "d2.size() = " <<  d2.size() << std::endl;

    std::cout <<  (d1 == d2 ? "d1 == d2" : "d1 != d2") << std::endl;
    std::deque<std::string> d3(d1);
    std::cout <<  (d2 == d3 ? "d2 == d3" : "d2 != d3") << std::endl;
    std::deque<std::string> d4(std::move(d1));
    std::cout <<  (d4 == d2 ? "d4 == d2" : "d4 != d2") << std::endl;
    // Expect != here because move semantic changed d1
    std::deque<std::string> d5 = std::move(d1);
    std::cout <<  (d5 == d2 ? "d5 == d2" : "d5 != d2") << std::endl;

    std::deque<std::string> d6(5);
    d6[0] = "hello";
    d6[1] = "world";
    d6[2] = "today";
    d6.at(3) = "is";
    d6.at(4) = "sunday";

    std::cout << "print elements in d6 : " << std::endl;
    copy(d6.cbegin(), d6.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
    std::cout << "d6.size() = " <<  d6.size() << std::endl;

    std::cout <<  (d6 == d2 ? "d6 == d2" : "d6 != d2") << std::endl;
}

void testAssignment() {
    std::deque<long> d1{10, 9, 8, 7, 6, 5};
    std::deque<long> d2{1, 2, 3, 4};
    std::deque<long> d3{1, 2, 3, 4};

    // Swap test
    std::cout << "before swap print d1 and d2" << std::endl;
    copy(d1.cbegin(), d1.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    copy(d2.cbegin(), d2.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    d1.swap(d2);
    std::cout << "after swap print d1 and d2" << std::endl;
    copy(d1.cbegin(), d1.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    copy(d2.cbegin(), d2.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;

    // assign test
    d3.assign(2, 12);
    std::cout << "after assign 2 12 ,  d3 :" << std::endl;
    copy(d3.cbegin(), d3.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    d1.assign(d1.begin() + 1, d1.end() - 1);
    std::cout << "after assign d1.begin() + 1, d1.end() - 1,  d1 :" << std::endl;
    copy(d1.cbegin(), d1.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
    d3.assign({1,2,3,4});
    std::cout << "after assign a initlist ,  d3 :" << std::endl;
    copy(d3.cbegin(), d3.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
}

void testIterator() {
    std::deque<int> fibonacci{1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    std::cout << "fibonacci:begin() == " << *fibonacci.begin() << std::endl;
    std::cout << "fibonacci:end() == " << *fibonacci.end() << std::endl;
    std::cout << "fibonacci:cbegin() == " << *fibonacci.cbegin() << std::endl;
    std::cout << "fibonacci:cend() == " << *fibonacci.cend() << std::endl;

    // Reverse a vector with assign and r-iterator.
    std::deque<int> tmp;
    tmp.assign(fibonacci.crbegin(), fibonacci.crend());
    swap(fibonacci, tmp);
    std::cout << "after reverse,  fibonacci:" << std::endl;
    copy(fibonacci.cbegin(), fibonacci.cend(), std::ostream_iterator<long>(std::cout, ","));
    std::cout << std::endl;
}

void testInsertOrRemove() {
    std::deque<char> dc{'I', ' ', 'a', 'm', ' ', 'a', 'd', 'o', 'r', 'a', 'b', 'l', 'e', '!', '\0'};
    if (dc.empty()) {
        std::cout << "vc is expected not empty" << std::endl;
    }
    printf("%s\n", &dc[0]);

    dc.pop_back();
    std::cout << "pop_back a character " << std::endl;
    dc.push_back('\0');
    std::cout << "push_back a character " << std::endl;
    dc.pop_front();
    std::cout << "pop_back a character " << std::endl;
    dc.push_front('I');
    std::cout << "push_back a character " << std::endl;
    copy(dc.cbegin(), dc.cend(), std::ostream_iterator<char>(std::cout));
    std::cout << std::endl;

    std::cout << "dc.size() = " << dc.size() << std::endl;
    std::deque<char>::iterator pos = find(dc.begin(), dc.end(), 'a');
    while (pos != dc.end()) {
        dc.erase(pos);
        pos = find(dc.begin(), dc.end(), 'a');
    }
    std::cout << "after remove all 'a', dc.size() = " << dc.size() << std::endl;

    // It plays same function as above:
    std::deque<char>  dc1(dc);
    dc1.erase(remove(dc1.begin(), dc1.end(), 'a'), dc1.end());
    std::cout << "after remove all 'a', dc1.size() = " << dc1.size() << std::endl;

    dc = {'I', ' ', 'a', 'm', ' ', 'a', 'd', 'o', 'r', 'a', 'b', 'l', 'e'};
    dc1.insert(dc1.begin()  +  2, 'a');
    dc1.insert(dc1.begin()  +  5, 'a');
    dc1.insert(dc1.begin()  +  9, 'a');
    std::cout <<  "after add back all 'a' " << (dc1 == dc ? "dc1 == dc" : "dc1 != dc") << std::endl;
    dc1.insert(dc1.begin() + 5, {});
    std::cout <<  "after add a empty list " << (dc1 == dc ? "dc1 == dc" : "dc1 != dc") << std::endl;

    dc1.clear();
    dc1.insert(dc1.end(), 'I');
    dc1.insert(dc1.end(), ' ');
    dc1.insert(dc1.end(), 'a');
    dc1.insert(dc1.end(), 'm');
    dc1.insert(dc1.end(), ' ');
    dc1.insert(dc1.end(), 'a');
    dc1.insert(dc1.end(), 'd');
    dc1.insert(dc1.end(), 'o');
    dc1.insert(dc1.end(), 'r');
    dc1.insert(dc1.end(), 'a');
    dc1.insert(dc1.end(), 'b');
    dc1.insert(dc1.end(), 'l');
    dc1.insert(dc1.end(), 'e');
    std::cout <<  "after clear and insert one by one " << (dc1 == dc ? "dc1 == dc" : "dc1 != dc") << std::endl;

    dc.resize(5);
    std::cout <<  "after resize dc " << (dc1 == dc ? "dc1 == dc" : "dc1 != dc") << std::endl;
}


auto main() -> int {
    std::deque<std::string> line_separator;
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
}
