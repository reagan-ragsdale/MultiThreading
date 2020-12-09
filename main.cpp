// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <chrono>
#include <ctime>

long long fib(long long n) {
  if (n < 2) {
    return n;
  } else {
    return fib(n-1) + fib(n-2);
  }
}

int main() {
  auto start_time = std::chrono::high_resolution_clock::now();
  long long input = 39;
  long long result = fib(input);
  auto end_time = std::chrono::high_resolution_clock::now();
  auto time = end_time - start_time;

  auto start_time2 = std::chrono::high_resolution_clock::now();
  long long input2 = 38;
  long long result2 = fib(input2);
  auto end_time2 = std::chrono::high_resolution_clock::now();
  auto time2 = end_time2 - start_time2;

  std::cout << "result = " << result << '\n';
  std::cout << "fib(" << input << ") took " <<
  time/std::chrono::milliseconds(1) << "ms to run.\n";

  std::cout << "\nresult2 = " << result2 << '\n';
  std::cout << "fib(" << input2 << ") took " <<
  time2/std::chrono::milliseconds(1) << "ms to run.\n";



  auto start_time3 = std::chrono::high_resolution_clock::now();
  long long input3 = 39;
  long long result3 = fib(input3);
  long long input4 = 38;
  long long result4 = fib(input4);
  auto end_time3 = std::chrono::high_resolution_clock::now();
  auto time3 = end_time3 - start_time3;
  std::cout << "\nresult3+4 = " << result3 << " + " << result4 <<'\n';
  std::cout << "fib(" << input3 << " + " << input4 <<") took " <<
  time3/std::chrono::milliseconds(1) << "ms to run.\n";

  auto finalTime1 = time/std::chrono::milliseconds(1) + time2/std::chrono::milliseconds(1);
  auto finalTime2 = time3/std::chrono::milliseconds(1);
  std::cout << "\nTwo single thread added time =" << finalTime1 << "\n"
  << "multithread time = " << finalTime2 <<'\n';


}
  