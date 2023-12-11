#ifndef tools_hpp
#define tools_hpp

#include <array>
#include <chrono>
#include <functional>
#include <iostream>
#define S std::

int cppVersion() {
    long version = __cplusplus;
    switch (version) {
    case 202101L: version = 23; break;
    case 202002L: version = 20; break;
    case 201703L: version = 17; break;
    case 201402L: version = 14; break;
    case 201103L: version = 11; break;
    case 199711L: version = 98; break;
    }
    return version;
}

// This function returns time in µs
float averageExecutionTime(S function<void()> code, int precision) {
    float time = 0;
    for (int i = 0; i < precision; i++) {
        auto start = std::chrono::system_clock::now();
        code();
        auto end = S chrono::system_clock::now();
        time += S chrono::duration_cast<S chrono::microseconds>(end - start).count();
    }
    return time / precision;
}

template <uint16_t size>

S string arrayToString(S array<char, size>& array) {
    S string returnVal;
    for (char C : array) {
        returnVal += C;
    }
    return returnVal;
}

#endif
