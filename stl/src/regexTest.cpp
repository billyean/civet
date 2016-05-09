#include <regex>
#include <iostream>

using namespace std;

void match(bool ismatch) {
    cout << (ismatch ? "matched" : "not matched") << endl;
}

void testMatch() {
    regex reg1("^\\d{3,3}-\\d{2,2}-\\d{4,4}$");
    match(regex_match("163-79-6721", reg1));
    match(regex_match("x63-79-6721", reg1));
    match(regex_match("163x79-6721", reg1));
    match(regex_match("1163-79-6721", reg1));
    match(regex_match("163-79-67211", reg1));

    regex reg2("^(\\d{3,3})-(\\d{2,2})-(\\d{4,4})$");
    match(regex_match("163-79-6721", reg2));
    match(regex_match("x63-79-6721", reg2));
    match(regex_match("163x79-6721", reg2));
    match(regex_match("1163-79-6721", reg2));
    match(regex_match("163-79-67211", reg2));

    match(regex_match("163-79-6721", regex("^(\\d{3,3})-(\\d{2,2})-(\\d{4,4})$")));
    match(regex_match("x63-79-6721", regex("^(\\d{3,3})-(\\d{2,2})-(\\d{4,4})$")));
    match(regex_match("163x79-6721", regex("^(\\d{3,3})-(\\d{2,2})-(\\d{4,4})$")));
    match(regex_match("1163-79-6721", regex("^(\\d{3,3})-(\\d{2,2})-(\\d{4,4})$")));
    match(regex_match("163-79-67211", regex("^(\\d{3,3})-(\\d{2,2})-(\\d{4,4})$")));

    regex reg4("^(\\d{3,3})-(\\d{2,2})-(\\d{4,4})$", regex_constants::grep);
    match(regex_match("163-79-6721", reg4));
    // match(regex_match("x63-79-6721", reg4));
    // match(regex_match("163x79-6721", reg4));
    // match(regex_match("1163-79-6721", reg4));
    // match(regex_match("163-79-67211", reg4));
}

auto main() -> int {
  testMatch();
  return 0;
}
