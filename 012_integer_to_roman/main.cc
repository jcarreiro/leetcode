#include <chrono>
#include "solution.h"

using namespace std;

int main(int argc, char* argv[]) {
  Solution s;

  constexpr auto kIterations{10'000};
  const auto& start = chrono::high_resolution_clock::now();

  for (int i = 0; i < kIterations; i++) {
    s.intToRoman(3749);
  }

  const auto& end = chrono::high_resolution_clock::now();
  chrono::duration<double, micro> duration = end - start;
  cout << "intToRoman: " << duration / kIterations << " per iteration." << endl;
  return 0;
}
