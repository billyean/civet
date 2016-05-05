#include <iostream>
#include <string>

constexpr auto greeting = "Hello World!";
auto lambda = [](std::string m) { return std::string("hello ") + m; };

int main(int argc, char* argv[]) {
  std::cout << greeting << std::endl;
  std::cout << lambda("Tristan") << std::endl;
}
