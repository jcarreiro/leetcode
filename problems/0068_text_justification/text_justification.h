#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/*
 * Given an array of strings words and a width maxWidth, format the text such
 * that each line has exactly maxWidth characters and is fully (left and right)
 * justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line does not divide evenly between words, the
 * empty slots on the left will be assigned more spaces than the slots on the
 * right.
 *
 * For the last line of text, it should be left-justified, and no extra space is
 * inserted between words.
 *
 * == Note ==
 * A word is defined as a character sequence consisting of non-space characters
 * only. Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth. The input array words contains at least one word.
 *
 * == Example 1 ==
 * === Input ===
 * - words = ["This", "is", "an", "example", "of", "text", "justification."]
 * - maxWidth = 16
 *
 * === Output ===
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 *
 * == Example 2 ==
 * === Input ===
 * - words = ["What","must","be","acknowledgment","shall","be"]
 * - maxWidth = 16
 *
 * === Output ===
 * [
 *   "What   must   be",
 *   "acknowledgment  ",
 *   "shall be        "
 * ]
 *
 * Explanation: Note that the last line is "shall be " instead of "shall be",
 * because the last line must be left-justified instead of fully-justified. Note
 * that the second line is also left-justified because it contains only one
 * word.
 *
 * == Example 3 ==
 *
 * === Input ===
 * - words = ["Science","is","what","we","understand","well","enough","to",
 *            "explain","to","a","computer.","Art","is","everything","else",
 *            "we","do"]
 * - maxWidth = 20
 *
 * === Output ===
 * [
 *   "Science  is  what we",
 *   "understand      well",
 *   "enough to explain to",
 *   "a  computer.  Art is",
 *   "everything  else  we",
 *   "do                  "
 * ]
 *
 * == Constraints ==
 * - 1 <= words.length <= 300
 * - 1 <= words[i].length <= 20
 * - words[i] consists of only English letters and symbols.
 * - 1 <= maxWidth <= 100
 * - words[i].length <= maxWidth
 */
class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> lines;
    int i = 0;
    while (i < words.size()) {
      // How many words can we fit on the next line?
      int j = i;
      int width = 0;
      while (j < words.size() && width < maxWidth) {
        const auto& nextWord = words[j];

        // The problem says that we'll never have a word that's longer than the
        // max width of a line, so we can assert on that.
        const auto wordLen = nextWord.length();
        assert(nextWord.length() <= maxWidth);

        // Add the length of this word to the width of the current line.
        width += wordLen;
        if (j > i) {
          // Include a space for each word after the first, since we need to put
          // at least one space between words.
          width++;
        }

        // Move on to the next word.
        j++;
      }

      // At this point, j is either pointing to the first word that wouldn't fit
      // on the line, or it's gone past the end of the words array, indicating
      // that all the remaining words will fit.
      //
      // Check to see if we've overflowed the width of the line, and if so, back
      // up one word in the input.
      if (width > maxWidth) {
        // Note that the j - 1 here is safe, since the problem definition says
        // that we'll never have a word longer than the maxWidth (so if we have
        // width > maxWidth, we must have at processed at least two words in the
        // loop above).
        assert(j > 0);
        const auto lastWordLen = words[j - 1].length();

        // It's also safe to assume there's a space to remove here, for the same
        // reason as above.
        width -= lastWordLen + 1;
        j--;
      }

      // Output any words we can fit.
      int wordsToWrite = j - i;
      int totalSpaces = maxWidth - width + wordsToWrite - 1;
      div_t spacesPerWord{totalSpaces, 0};
      if (wordsToWrite > 1) {
        spacesPerWord = div(totalSpaces, wordsToWrite - 1);
      }

      auto extraSpaces = spacesPerWord.rem;

      // We can pre-allocate the line, since we know it will always be exactly
      // maxWidth characters long.
      vector<char> line;
      size_t wp = 0;
      line.resize(maxWidth + 1);
      for (; i < j; i++) {
        wp += write(&line[wp], words[i]);
        if (j == words.size()) {
          // This is the last line, so it needs to be left-justified, with only
          // a single space between words.
          if (i < j - 1 && wordsToWrite > 1) {
            wp += writeSpaces(&line[wp], 1);
          } else {
            // Write any remaining spaces needed to fill up the line.
            wp += writeSpaces(&line[wp], totalSpaces - wordsToWrite + 1);
          }
        } else if (i < j - 1 || wordsToWrite == 1) {
          int k = spacesPerWord.quot;
          if (extraSpaces > 0) {
            k++;
            extraSpaces--;
          }

          wp += writeSpaces(&line[wp], k);
        }
      }
      lines.push_back(&line[0]);
    }
    return lines;
  }

 private:
  size_t write(char *buf, const std::string& s) {
    size_t i = 0;
    while (i < s.length()) {
      *buf++ = s[i++];
    }
    return s.length();
  }

  size_t writeSpaces(char *buf, const size_t count) {
    for (int i = 0; i < count; i++) {
      *buf++ = ' ';
    }
    return count;
  }
};
