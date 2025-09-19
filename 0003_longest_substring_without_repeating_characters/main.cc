#include <chrono>
#include "solution.h"

using namespace std;

void benchmark(const std::function<void()>& fn, const std::string& name,
               size_t iterationCount = 10'000) {
  const auto& start = chrono::high_resolution_clock::now();

  for (int i = 0; i < iterationCount; i++) {
    fn();
  }

  const auto& end = chrono::high_resolution_clock::now();
  chrono::duration<double, micro> duration = end - start;
  cout << name << ": " << duration / iterationCount << " per iteration."
       << endl;
}

int main(int argc, char* argv[]) {
  benchmark([]() { return; }, "nop");
  // Add additional benchmark calls here:
  std::string s{"the quick brown fox jumps over the lazy dog"};
  Solution solution;
  benchmark([&]() { solution.lengthOfLongestSubstring(s); }, "length_of_longest_substring");
  return 0;
}
