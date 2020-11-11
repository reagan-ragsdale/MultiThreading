// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <chrono>

using namespace std;

void foo() 
{
  for (int i=0; i < 10000; i++) {
    cout << "foo(): " << i << "\n";
     std::this_thread::sleep_for (std::chrono::seconds(1));
  }
}

void bar(int x)
{
    for (int i=0; i < 10000; i++) {
      cout << "I'm in bar(" << x << "): " << i << "\n";
     std::this_thread::sleep_for (std::chrono::seconds(1));
  }

}

int main() 
{
  thread first (foo);
  thread second (bar,0);

  first.join();
  second.join();

  cout << "foo and bar completed.\n";

  return 0;
}