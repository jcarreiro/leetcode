#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

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
    set<int> wordsMatched;
    map<char, shared_ptr<TrieNode>> children;

    shared_ptr<TrieNode> addChild(const char c) {
      auto child = getChild(c);
      if (!child) {
        child = make_shared<TrieNode>();
        children[c] = child;
      }
      return child;
    }

    shared_ptr<TrieNode> getChild(const char c) {
      auto it = children.find(c);
      if (it != children.end()) {
        return it->second;
      }
      return nullptr;
    }
  };

  shared_ptr<TrieNode> buildTrie(const vector<string>& words) {
    auto root = make_shared<TrieNode>();
    for (int i = 0; i < words.size(); i++) {
      auto node = root;
      const auto& word = words[i];
      for (const auto& c : word) {
        node = node->addChild(c);
      }
      node->wordsMatched.insert(i);
    }
    return root;
  }

  set<int> matchWord(const std::string& s, int startPos, int wordLength,
                     const shared_ptr<TrieNode> trieRoot) {
    int endPos = startPos + wordLength;
    if (endPos > s.size()) {
      // Not enough characters left to match a whole word.
      return {};
    }

    auto trieNode = trieRoot;
    for (; startPos < endPos; startPos++) {
      trieNode = trieNode->getChild(s[startPos]);
      if (!trieNode) {
        // We didn't match any word in the trie.
        return {};
      }
    }
    // If we get here, then we must have matched a word.
    assert(!trieNode->wordsMatched.empty());
    return trieNode->wordsMatched;
  }

  int markWordAsUsed(int startPos, int pos, int wordLength,
                     const set<int>& wordsMatched, vector<int>& usedWords) {
    assert(!wordsMatched.empty());
    int bestWordIndex = -1;
    int bestWordEndPos = -1;
    for (const auto widx : wordsMatched) {
      int endPos = usedWords[widx];
      if (endPos < startPos) {
        // This word isn't used yet in this match.
        bestWordIndex = widx;
        bestWordEndPos = -1;
        break;
      }

      if (bestWordEndPos == -1 || endPos < bestWordEndPos) {
        bestWordIndex = widx;
        bestWordEndPos = endPos;
      }
    }

    // Update the end position of the used word.
    usedWords[bestWordIndex] = pos + wordLength;

    // If the word was used, return the adjusted start pos.
    if (bestWordEndPos != -1) {
      return bestWordEndPos;
    }
    return startPos;
  }

  vector<int> findSubstringTrie(string s, vector<string>& words) {
    if (words.empty()) {
      // There are no words to match.
      return {};
    }

    const int wordLength = static_cast<int>(words[0].length());
    const int substrLength = static_cast<int>(wordLength * words.size());
    if (s.size() < substrLength) {
      // The string isn't long enough to have all of the words in it.
      return {};
    }

    // Build the trie to use for matching words.
    auto trieRoot = buildTrie(words);

    // ba, ab, bb
    //
    // abbabba

    // The vector of starting positions for all of the concatenated substrings.
    vector<int> startPositions;

    // Loop over the possible starting positions for a match: [0..wordLen].
    for (int offset = 0; offset < wordLength; offset++) {
      // The start of the current substring.
      int startPos = offset;

      // An array with the end position for any already matched words; ie.,
      // if the words are ["foo", "bar", ...] and the string is "foobar...",
      // then the array would have [3, 6, ...] after matching "foo" and "bar".
      // This is the position we should advance to if we need to "re-use" the
      // word while matching.
      vector<int> usedWords(words.size(), -1);

      // Match words, starting at our offset.
      for (auto pos = offset; pos < s.length(); pos += wordLength) {
        // Try to match the next word.
        const auto wordsMatched = matchWord(s, pos, wordLength, trieRoot);
        if (wordsMatched.empty()) {
          // We didn't match any word; update our startPos and loop.
          startPos = pos + wordLength;
          continue;
        }

        // We matched one or more words in the word list (the latter is only
        // possible if there are duplicates). Mark the word as used. If the
        // word was already used, this function will return a new startPos.
        startPos =
            markWordAsUsed(startPos, pos, wordLength, wordsMatched, usedWords);

        // If we've matched all the words in the words array, then the
        // current match start is a solution, so add it to the output
        // array and move up the start position for the next loop.
        int endPos = pos + wordLength;
        if (endPos - startPos == substrLength) {
          // Record this start position in our list.
          startPositions.push_back(startPos);

          // Move the start position up past the first word in the match.
          startPos += wordLength;
        }
      }
    }

    return startPositions;
  }

  vector<int> findSubstringHash(string s, vector<string>& words) {
    if (words.empty()) {
      // There are no words to match.
      return {};
    }

    const auto wordLength = words[0].length();
    const auto matchLength = wordLength * words.size();
    if (s.size() < matchLength) {
      // The string isn't long enough to have all of the words in it.
      return {};
    }

    // The vector of starting indices for the matched substrings.
    vector<int> startPositions;

    // Loop, checking each possible starting offset in the string.
    for (size_t offset = 0; offset < wordLength; offset++) {
      // The window start position.
      auto startPos = offset;

      struct WordData {
        deque<size_t> q;
        size_t count;
      };

      unordered_map<string_view, WordData> wordMap;
      for (const auto& word : words) {
        auto& wd = wordMap[word];
        wd.count++;
      }

      // Try to match each word in the string, start from our current offset.
      for (size_t pos = offset; pos < s.length(); pos += wordLength) {
        auto endPos = pos + wordLength;

        // If there's not at least a word's worth of characters, left, then
        // we can't match another word.
        if (endPos > s.length()) {
          break;
        }

        // Get the next word. Because all words are the same length, we can
        // just read the next wordLength characters.
        string_view word{s.data() + pos, wordLength};

        // Check to see if this word is one of the words in our list. This is
        // O(1) since we use a hash map.
        auto it = wordMap.find(word);
        if (it == wordMap.end()) {
          // This word isn't our on list -- move the start position up and
          // keep checking.
          startPos = endPos;
          continue;
        }

        // This word is on our list. Check to see if we've used it already in
        // the current match.
        auto& wd = it->second;
        auto& q = wd.q;
        if (!q.empty()) {
          // This word has already been used. Check to see if we've used all of
          // the copies in our words list.
          if (q.size() == wd.count) {
            // We've used all the copies of this word already, so we need to
            // re-use one. Pop the first end position off the queue, then move
            // our window start position up past it. This shrinks our window
            // and removes the first occurrence of the word from the match.
            const auto wordEndPos = q.front();
            q.pop_front();

            // If the word end position is before our current window start,
            // then this word wasn't actually used in this match window, so
            // we don't need to move up our start position.
            if (wordEndPos > startPos) {
              startPos = wordEndPos;
            }
          }
        }

        // Add the word end position to the queue to mark this word as used.
        q.push_back(endPos);

        // Check to see if we have a full window, and if so, record the match.
        if (endPos - startPos == matchLength) {
          // Record this match.
          startPositions.push_back(static_cast<int>(startPos));

          // Move the window start position up past the first word.
          startPos += wordLength;
        }
      }
    }

    return startPositions;
  }

  vector<int> findSubstring(string s, vector<string>& words) {
    return findSubstringHash(s, words);
  }
};
