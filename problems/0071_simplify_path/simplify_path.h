// Copyright 2026 Jason M. Carreiro.

#pragma once

#include <deque>
#include <string>
#include <string_view>

using namespace std;

// # 71. Simplify Path
//
// Difficulty: Medium
//
// You are given an absolute path for a Unix-style file system, which always
// begins with a slash '/'. Your task is to transform this absolute path into
// its simplified canonical path.
//
// The rules of a Unix-style file system are as follows:
// - A single period '.' represents the current directory.
// - A double period '..' represents the previous/parent directory.
// - Multiple consecutive slashes such as '//' and '///' are treated as a single
//   slash '/'.
// - Any sequence of periods that does not match the rules above should be
//   treated as a valid directory or file name. For example, '...' and '....'
//   are valid directory or file names.
//
// The simplified canonical path should follow these rules:
// - The path must start with a single slash '/'.
// - Directories within the path must be separated by exactly one slash '/'.
// - The path must not end with a slash '/', unless it is the root directory.
// - The path must not have any single or double periods ('.' and '..') used to
//   denote current or parent directories.
//
// Return the simplified canonical path.
//
// ## Example 1
// Input: path = "/home/"
// Output: "/home"
// Explanation:
// The trailing slash should be removed.
//
// ## Example 2
// Input: path = "/home//foo/"
// Output: "/home/foo"
// Explanation:
// Multiple consecutive slashes are replaced by a single one.
//
// ## Example 3
// Input: path = "/home/user/Documents/../Pictures"
// Output: "/home/user/Pictures"
// Explanation:
// A double period ".." refers to the directory up a level (the parent
// directory).
//
// ## Example 4
// Input: path = "/../"
// Output: "/"
// Explanation:
// Going one level up from the root directory is not possible.
//
// ## Example 5
// Input: path = "/.../a/../b/c/../d/./"
// Output: "/.../b/d"
// Explanation:
// "..." is a valid name for a directory in this problem.
//
// ## Constraints
// - 1 <= path.length <= 3000
// - path consists of English letters, digits, period '.', slash '/' or '_'.
// - path is a valid absolute Unix path.
class Solution {
public:
  string simplifyPath(string path) {
    // We iterate over the components of path, pushing them onto the back of a
    // deque, and handling '.' and '..' as we go. Once we've iterated over all
    // the path components and pushed them onto the deque, we can iterate over
    // the elements in the queue, from front to back, building the simplified
    // path to return.
    string_view sv(path);
    deque<string> q;
    size_t i = 0;
    while (i < path.size()) {
      // skip any leading '/'s
      while (i < path.size() && path[i] == '/') {
        i++;
      }

      // ignore any trailing slashes at the end of the path
      if (i == path.size()) {
        break;
      }

      // get the next component of the path
      size_t j = i + 1;
      while (j < path.size() && path[j] != '/') {
        j++;
      }
      string_view c = sv.substr(i, j - i);
      i = j;

      // if it's a '.', just skip it
      if (c == ".") {
        continue;
      }

      // if it's a '..', go up one level
      if (c == "..") {
        if (!q.empty()) {
          q.pop_back();
        }
        continue;
      }

      // anything else, push on to stack
      q.emplace_back(c);
    }

    // join the path components in the stack and return
    string result;
    result.reserve(path.size() + 1); // worst case is same length
    result += "/";
    for (int i = 0; i < q.size(); i++) {
      if (i > 0) {
        result += "/";
      }
      result += q[i];
    }
    return move(result);
  }
};
