// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <stack>
#include <utility>

using namespace std;

// # 155. Min Stack
//
// Difficulty: Medium
//
// Design a stack that supports push, pop, top, and retrieving the minimum
// element in constant time.
//
// Implement the MinStack class:
// - MinStack() initializes the stack object.
// - void push(int value) pushes the element value onto the stack.
// - void pop() removes the element on the top of the stack.
// - int top() gets the top element of the stack.
// - int getMin() retrieves the minimum element in the stack.
// - You must implement a solution with O(1) time complexity for each function.
//
// ## Example 1
// ### Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
//
// ### Output
// [null,null,null,null,-3,null,0,-2]
//
// ### Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
//
// ## Constraints
// - -2^31 <= val <= 23^1 - 1
// - Methods pop, top and getMin operations will always be called on non-empty
//   stacks.
// - At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
//
// # Solution
// We keep a stack of pairs, where each pair has the element itself, and the
// current minimum element, which can only change when a new minimum element
// is pushed on to the stack. This allows us to implement all of push(), pop(),
// top(), and getMin() in O(1) time.
class MinStack {
public:
  MinStack() {}

  void push(int value) {
    int m = s.empty() ? value : min(value, s.top().second);
    s.emplace(value, m);
  }

  void pop() { s.pop(); }

  int top() { return s.top().first; }

  int getMin() { return s.top().second; }

  stack<pair<int, int>> s;
};