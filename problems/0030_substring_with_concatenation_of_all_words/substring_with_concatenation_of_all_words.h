#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <memory>

using namespace std;

/*
 * You are given a string s and an array of strings words. All the strings of
 * words are of the same length.
 *
 * A concatenated string is a string that exactly contains all the strings of
 * any permutation of words concatenated.
 *
 * For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef",
 * "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is
 * not a concatenated string because it is not the concatenation of any
 * permutation of words. Return an array of the starting indices of all the
 * concatenated substrings in s. You can return the answer in any order.
 *
 * == Example 1 ==
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 * Output: [0,9]
 * Explanation:
 * The substring starting at 0 is "barfoo". It is the concatenation of
 * ["bar","foo"] which is a permutation of words.
 *
 * The substring starting at 9 is "foobar". It is the concatenation of
 * ["foo","bar"] which is a permutation of words.
 *
 * == Example 2 ==
 * Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * Output: []
 * Explanation:
 * There is no concatenated substring.
 *
 * == Example 3 ==
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * Output: [6,9,12]
 * Explanation:
 * The substring starting at 6 is "foobarthe". It is the concatenation of
 * ["foo","bar","the"].
 *
 * The substring starting at 9 is "barthefoo". It is the concatenation of
 * ["bar","the","foo"].
 *
 * The substring starting at 12 is "thefoobar". It is the concatenation of
 * ["the","foo","bar"].
 *
 * == Constraints ==
 * - 1 <= s.length <= 10^4
 * - 1 <= words.length <= 5000
 * - 1 <= words[i].length <= 30
 * - s and words[i] consist of lowercase English letters.
 */
class Solution {
public:
  struct TrieNode {
    map<char, shared_ptr<TrieNode>> children;

    shared_ptr<TrieNode> getChild(const char c) {
      auto it = children.find(c);
      if (it != children.end()) {
        return it->second;
      }

      auto node = make_shared<TrieNode>();
      children[c] = node;
      return node;
    }
  };

  shared_ptr<TrieNode> buildTrie(const vector<string>& words) {
    auto root = make_shared<TrieNode>();

    for (const auto& word : words) {
      auto node = root;
      for (const auto& c : word) {
        cout << "Got letter: " << c << endl;
        node = node->getChild(c);
      }
    }

    return root;
  }

  vector<int> findSubstring(string s, vector<string>& words) {
    if (words.empty()) {
      return {};
    }

    auto root = buildTrie(words);

    cout << "Got trie root: " << root << endl;

    // Loop over the possible starting positions for a match (0..wordLen).
    const int wordLen = words[0].length();
    for (int offset = 0; offset < wordLen; offset++) {
      cout << "offset: " << offset << endl;

      // Scan forward from the offset, matching words from our word list.
      const auto& node = root;
      for (auto i = offset; i < s.length(); i++) {
        cout << "i: " << i << endl;

        // Try to extend our current match.

      }
    }

    return {};
  }
};
