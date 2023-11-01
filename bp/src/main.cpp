//
// Created by haibo on 10/31/23.
//
#include <future>
#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

std::mutex m;
std::condition_variable cv;
using namespace std::chrono;
auto main() -> int {
    auto v = std::make_shared<int>(0);
    std::vector<std::future<void>> results;
    for (int i = 0; i < std::thread::hardware_concurrency(); i++) {
        results.push_back( std::async(std::launch::async, [v]() {
            for (int x = 0; x < 4; x++) {
                {
                    std::unique_lock lk(m);
                    cv.wait(lk, [v, x]{
                        return (*v)  == x;
                    });
                }
                using namespace std::chrono_literals;
//                auto start = high_resolution_clock::now();
                long l = 0;
                for (long j = 0; j < 0x7fffffff; j++) {
                    l += j;
                }
                std::cout << std::this_thread::get_id() << " - " << x << " : " << l << std::endl;
//                auto duration = duration_cast<milliseconds>(high_resolution_clock::now() - start);
//                std::cout << duration.count() << " ms" << std::endl;
            }
            std::cout << "End" << std::endl;
        }));
    }
    for (int i = 0; i < 4; i++) {
        using namespace std::chrono_literals;
        {
            std::unique_lock lk(m);
            (*v) = i;
        }
        cv.notify_all();
        std::this_thread::sleep_for(8s);
    }
    for (auto iter = results.begin(); iter != results.end(); iter++) {
        iter->wait();
    }
    return 0;
}
