//
// Created by haibo on 8/1/23.
//
#include "MyThreadPool.h"
#include <vector>
#include <future>
#include <iostream>
#include <cmath>

using namespace std;

auto main() -> int {
  MyThreadPool pool;
  vector<future<void>> results;

  for (int i = 1; i <= 1000000; i++) {
    switch ( i % 5) {
      case 0:
        results.emplace_back(pool.asyncall([](){
          long sum = 0;
          for (int i = 1; i <= 1000000; i++) {
            sum += i;
          }
          cout << "Sum of [1, 1000000] is " << sum << "." << endl;
        }));
        break;
      case 1:
        results.emplace_back(pool.asyncall([](){
          long sum = 0;
          for (int i = 1; i <= 1000000; i++) {
            sum += i * (i + 1);
          }
          cout << "Sum of [1, 1000000] product [2, 1000001] is " << sum << "." << endl;
        }));
        break;
      case 2:
        results.emplace_back(pool.asyncall([](){
          long prime = 8;
          int i = 4;
          while (i < 1000) {
            for (int j = 2; j <= sqrt(prime); j++) {
              if (prime % j == 0) {
                i++;
                prime++;
                break;
              }
            }
            prime++;
          }
          cout << "1000th prime number is " << prime << "." << endl;
        }));
        break;
      case 3:
        results.emplace_back(pool.asyncall([](){
          long fibonacci0 = 0;
          long fibonacci = 1;
          for (int i = 1; i < 10000; i++) {
            long temp = fibonacci + fibonacci0;
            fibonacci0 = fibonacci;
            fibonacci = temp;
          }
          cout << "10000th fibonacci number is " << fibonacci << "." << endl;
        }));
        break;
      default:
        results.emplace_back(pool.asyncall([](){
          srand((unsigned) time(NULL));
          std::vector<long> primes;
          long upperbound = 9999999999;
          long lowerbound = 1000000000;
          for (int i = 0; i < 4; i++) {
            bool not_prime = true;
            while (not_prime) {
              long randNum = rand() % (upperbound - lowerbound + 1) + lowerbound;
              bool found = true;
              for (int j = 2; j <= sqrt(randNum); j++) {
                if (randNum % j == 0) {
                  found = false;
                  break;
                }
              }
              if (found) {
                not_prime = false;
                primes.push_back(randNum);
              }
            }
          }
          cout << "Found 4 prime numbers between [1000000000, 9999999999] ";
          for (auto i = primes.begin(); i != primes.end(); ++i)
            cout << *i << ',';
          cout << endl;
        }));
        break;
    }
    if(i % 50000 == 0) {
      std::this_thread::sleep_for(15000ms);
    }
  }

  for (auto iter = results.begin(); iter != results.end(); ++iter) {
    iter->wait();
  }
  cout << "End of execution." << endl;

  return 0;
}
