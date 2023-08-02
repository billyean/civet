//
// Created by haibo on 8/1/23.
//
#include "MyThreadPool.h"
#include <vector>
#include <future>
#include <iostream>
#include <cmath>
#include <pthread.h>

using namespace std;


bool isPrime(long candidate) {
  for (long j = 2; j <= sqrt(candidate); j++) {
    if (candidate % j == 0) {
      return false;
    }
  }
  return true;
}

auto main() -> int {
  MyThreadPool pool;
  vector<future<void>> results;

  for (int i = 1; i <= 1000000; i++) {
    switch ( i % 5) {
      case 0:
        results.emplace_back(pool.asyncall([](){
          long sum = 0;
          for (int i = 1; i <= INT16_MAX; i++) {
            sum += i;
          }
          cout << "In thread[" << pthread_self() << "]: calculate sum of [1, " << INT16_MAX <<  "] is " << sum << "." << endl;
        }));
        break;
      case 1:
        results.emplace_back(pool.asyncall([](){
          long sum = 0;
          for (long i = 1; i < INT32_MAX - 1; i++) {
            sum += i * (i + 1);
          }
          cout << "In thread[" << pthread_self() << "]: calculate sum of [1, " << INT32_MAX - 1 << "] product [2, " << INT32_MAX << "] is " << sum << "." << endl;
        }));
        break;
      case 2:
        results.emplace_back(pool.asyncall([](){
          long prime = 8;
          int i = 4;
          while (i < 10000) {
            while (!isPrime(++prime)){}
            i++;
          }
          cout << "In thread[" << pthread_self() << "]: found 10000th prime number is " << prime << "." << endl;
        }));
        break;
      case 3:
        results.emplace_back(pool.asyncall([](){
          long long fibonacci0 = 0;
          long long fibonacci = 1;
          for (int i = 1; i < 10000; i++) {
            long long temp = fibonacci + fibonacci0;
            fibonacci0 = fibonacci;
            fibonacci = temp;
          }
          cout << "In thread[" << pthread_self() << "]: found 10000th fibonacci number is " << fibonacci << "." << endl;
        }));
        break;
      default:
        results.emplace_back(pool.asyncall([](){
          srand((unsigned) time(NULL));
          std::vector<long> primes;
          long upperbound = 99999999999;
          long lowerbound = 10000000000;
          for (int i = 0; i < 20; i++) {
            long randNum;
            for(randNum = rand() % (upperbound - lowerbound + 1) + lowerbound; !isPrime(randNum);
              randNum = rand() % (upperbound - lowerbound + 1) + lowerbound) {
            }
            primes.push_back(randNum);
          }
          cout << "In thread[" << pthread_self() << "]: Found 20 prime numbers between [1000000000, 9999999999] ";
          for (auto i = primes.begin(); i != primes.end(); ++i)
            cout << *i << ',';
          cout << endl;
        }));
        break;
    }
    if(i % 500 == 0) {
      std::this_thread::sleep_for(60000ms);
    }
  }

  int j = 0;
  for (auto iter = results.begin(); iter != results.end(); ++iter) {
    iter->wait();
    j++;
    if (++j / 400  == 0) {
      std::this_thread::sleep_for(30000ms);
    }
  }
  cout << "End of execution." << endl;

  return 0;
}

