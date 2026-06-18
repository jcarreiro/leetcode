#pragma once

#include <chrono>
#include <iostream>

// High‑precision timing helper for benchmarking inside tests
template <typename Func>
auto time_it(Func&& f) {
  auto start = chrono::high_resolution_clock::now();
  auto result = f();
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<double, milli> ms = end - start;
  cout << "[ timing ] " << ms.count() << " ms\n";

  return result;
}
