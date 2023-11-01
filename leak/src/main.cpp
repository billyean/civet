#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include <future>

std::shared_ptr<int> val;
std::mutex m;
void printData() {
    {
        std::unique_lock l(m);
        if (!val) {

            val = std::make_shared<int>(42);
        }
    }
    std::cout << *val;
}
int main()
{
    std::async(printData);
    std::async(printData);
}