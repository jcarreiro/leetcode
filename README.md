# jcarreiro's Leetcode Solutions

This repository contains jcarreiro's C++ solutions for LeetCode problems. It 
uses CMake for builds and supports running tests with CTest or the generated
test targets.

## Repository Structure
- **CMakeLists**: [CMakeLists.txt](CMakeLists.txt) — top-level CMake project.
- **Entry point**: [main.cc](main.cc) — optional runner used by some examples.
- **Build output**: `build/` — CMake-generated build artifacts and solution/project files.
- **Problems**: [problems/](problems/) — each problem lives in its own folder, e.g. [problems/0289_game_of_life/game_of_life.h](problems/0289_game_of_life/game_of_life.h).
- **Includes**: [include/](include/) — shared headers such as [include/test_utils.h](include/test_utils.h).

## Quick Start (cross-platform)
1. Create and enter a build directory:

```
mkdir build
cd build
```

2. Configure the project with CMake:

```
cmake ..
```

3. Build the default target:

```
cmake --build . --config Release
```

Notes for Windows/Visual Studio: if you need a specific generator, pass `-G "Visual Studio 17 2022"` (or your installed generator) to the `cmake` command.

### Run Tests
- From the `build/` directory run all tests with CTest:

```
ctest --output-on-failure
```

- Or build and run the test target (Visual Studio builds will produce `RUN_TESTS` target):

```
cmake --build . --target RUN_TESTS --config Release
```

To run a single test by name or regex use:

```
ctest -R <regex>
```

### VS Code integration
- A `CMake: build` task is available in this workspace. Use the VS Code Command Palette or the Tasks menu to invoke it.

## How to Add a Solution
1. Add a new folder under `problems/` named with the LeetCode id and short slug, e.g. `0289_game_of_life`.
2. Place your solution files (headers and sources) and an accompanying test/executable that exercises the solution.
3. Reconfigure CMake to pick up the new problem code and tests.

Suggested layout in a problem folder:

- `problem_name.h` — solution code
- `problem_name_test.cpp` — small driver / unit tests using the shared test utilities
- (optional) `README.md` — notes about approach and complexity

## Coding Guidelines
- Prefer modern idiomatic C++ (C++11/14/17 compatible depending on target).
- Keep each problem self-contained for easier testing and review.

## Contributions
This repository contains my personal solutions to Leetcode problems, and so 
contributions from others will not be accepted. However you are free to read
the code and re-use it as desired to help you in your own studies.

## License
This repository is copyright © 2026 Jason Carreiro and is licensed under the MIT
License (see [LICENSE](LICENSE) for details). If you reuse problem statements or
test data, follow LeetCode's terms of use and provide appropriate attribution.