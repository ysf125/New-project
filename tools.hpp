#ifndef tools_hpp
#define tools_hpp
#include <chrono>
#include <functional>
#include <iostream>
#define S std::

float averageExecutionTimeInµs(S function<void()> code, int precision) {
  float time = 0;
  for (int i = 0; i < precision; i++) {
    auto start = std::chrono::system_clock::now();
    code();
    auto end = S chrono::system_clock::now();
    time += S chrono::duration_cast<S chrono::microseconds>(end - start).count();
    S cout << time << " " ;
  }
  return time / precision;
}

#endif