build/solution: solution.cc
	mkdir -p build
	g++ --std=c++20 -g -O0 -I /opt/homebrew/Cellar/googletest/1.17.0/include -L /opt/homebrew/Cellar/googletest/1.17.0/lib -l gtest -l gtest_main -o build/solution solution.cc

test: build/solution
	./build/solution

.PHONY: test
