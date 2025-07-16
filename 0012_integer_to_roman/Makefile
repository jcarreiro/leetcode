build/solution: solution.h solution_test.cc
	mkdir -p build
	g++ --std=c++20 -g -O0 -I /opt/homebrew/Cellar/googletest/1.17.0/include -fsanitize=address,undefined -L /opt/homebrew/Cellar/googletest/1.17.0/lib -l gtest -l gtest_main -o build/solution solution_test.cc

build/solution_prof: solution.h main.cc
	mkdir -p build
	g++ --std=c++20 -g -O2 -I /opt/homebrew/Cellar/googletest/1.17.0/include -L /opt/homebrew/Cellar/googletest/1.17.0/lib -l gtest -o build/solution_prof main.cc

benchmark: build/solution_prof
	./build/solution_prof

profile: build/solution_prof
	xctrace record --template 'Time Profiler' --launch build/solution_prof

test: build/solution
	./build/solution

.PHONY: benchmark profile test
