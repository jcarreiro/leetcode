// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <cassert>
#include <stack>
#include <string>

using namespace std;

// # 20. Valid Parentheses
//
// Difficulty: Easy
//
// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// An input string is valid if:
// - Open brackets must be closed by the same type of brackets.
// - Open brackets must be closed in the correct order.
// - Every close bracket has a corresponding open bracket of the same type.
//
// ## Example 1
// Input: s = "()"
// Output: true
//
// ## Example 2
// Input: s = "()[]{}"
// Output: true
//
// ## Example 3
// Input: s = "(]"
// Output: false
//
// ## Example 4
// Input: s = "([])"
// Output: true
//
// ## Example 5
// Input: s = "([)]"
// Output: false
//
// ## Constraints
// - 1 <= s.length <= 10^4
// - s consists of parentheses only '()[]{}'.
class Solution {
public:
  bool isValid(string s) {
    // The easy, obvious solution here is to keep track of the opening braces
    // using a stack; then, when we see a closing brace, we can check the stack
    // to make sure it matches. If the stack is empty when we see a closing
    // brace, then the string is not valid (more closing braces than opening)
    // and if we have braces left on the stack after iterating the string, then
    // string is also not valid (more opening brances than closing).
    stack<char> t;
    for (const auto& c : s) {
      if (c == '(' || c == '{' || c == '[') {
        // Push this open brace onto the stack.
        t.push(c);
      } else if (c == ')' || c == '}' || c == ']') {
        // Check that we have an open brace on the stack.
        if (t.empty()) {
          // No open brace to match.
          return false;
        }

        const auto& d = t.top();
        // Check that the braces match.
        if ((d == '(' && c != ')') || (d == '{' && c != '}') ||
            (d == '[' && c != ']')) {
          return false;
        }
        t.pop();
      } else {
        // The string should only have braces.
        assert(0);
      }
    }
    // If there are any unclosed braces, the string is not valid.
    return t.empty();
  }
};
