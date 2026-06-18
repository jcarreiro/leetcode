// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <stack>
#include <string>

using namespace std;

// # 224. Basic Calculator
//
// Difficulty: Hard
//
// Given a string s representing a valid expression, implement a basic
// calculator to evaluate it, and return the result of the evaluation.
//
// Note: You are not allowed to use any built-in function which evaluates
// strings as mathematical expressions, such as eval().
//
// ## Example 1
// Input: s = "1 + 1"
// Output: 2
//
// ## Example 2
// Input: s = " 2-1 + 2 "
// Output: 3
//
// ## Example 3
// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23
//
// ## Constraints
// - 1 <= s.length <= 3 * 10^5
// - s consists of digits, '+', '-', '(', ')', and ' '.
// - s represents a valid expression.
// - '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is
//   invalid).
// - '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is
//   valid).
// - There will be no two consecutive operators in the input.
// - Every number and running calculation will fit in a signed 32-bit integer.
class Solution {
 public:
  int calculate(string s) {
    // We accumulate digits into a current value, adding it to our result when
    // we encounter a non-digit character (e.g. '+'). We also track the current
    // sign; to handle subtraction (and unary negation), we flip the current
    // sign bit to -1 when we encounter a '-' character. Thus when parsing an
    // expression like "2-1", first we parse the '2' and accumlate it into our
    // current value; then we encounter the '-', add the 2 to the result, and
    // flip the current sign; and finally, we parse the '1', and add it to the
    // result, negated.
    //
    // To handle grouping ('('), we use a stack to store the state of the outer
    // sign bit and partial result. When we encounter a '(', we push the current
    // sign and result onto the stack; then, when we encounter a ')', we pop off
    // the previous sign state and partial result, and add the sub-expression's
    // value to the outer result.
    stack<pair<int, int>> t;
    int n = 1;
    long v = 0;  // use a wider type to handle parsing -MAX_INT correctly
    int r = 0;
    for (const auto& c : s) {
      if (isdigit(c)) {
        // accumulate digits into current value
        v = v * 10 + (c - '0');
      } else if (c == '+') {
        // add value into result, appying sign, then reset sign to positive for
        // next value (and reset value)
        r += n * v;
        n = 1;
        v = 0;
      } else if (c == '-') {
        // add value into result, applying sign, then reset sign to negative for
        // next value (and reset value)
        r += n * v;
        n = -1;
        v = 0;
      } else if (c == '(') {
        // push the current sign and result onto the stack, then reset them for
        // the sub-expression.
        t.push({n, r});
        n = 1;
        r = 0;
      } else if (c == ')') {
        // add value into result, applying sign, then reset value; this gives us
        // the total value for the sub-expression.
        r += n * v;
        v = 0;

        // pop the outer sign and result off the stack, then apply the value of
        // the sub-expression to the outer result.
        const auto& [sign, outerResult] = t.top();
        t.pop();
        r = outerResult + (sign * r);
      }
    }
    // add in the last term
    r += n * v;
    return r;
  }
};
