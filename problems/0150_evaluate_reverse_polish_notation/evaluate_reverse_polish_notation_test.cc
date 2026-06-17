#include "evaluate_reverse_polish_notation.h"
#include <gtest/gtest.h>

TEST(EvaluateReversePolishNotationTest, Test01) {
  Solution s;
  vector<string> tokens{"2", "1", "+", "3", "*"};
  EXPECT_EQ(s.evalRPN(tokens), 9);
}

TEST(EvaluateReversePolishNotationTest, Test02) {
  Solution s;
  vector<string> tokens{"4", "13", "5", "/", "+"};
  EXPECT_EQ(s.evalRPN(tokens), 6);
}

TEST(EvaluateReversePolishNotationTest, Test03) {
  Solution s;
  vector<string> tokens{"10", "6", "9",  "3", "+", "-11", "*",
                        "/",  "*", "17", "+", "5", "+"};
  EXPECT_EQ(s.evalRPN(tokens), 22);
}
