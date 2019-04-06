/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (34.77%)
 * Total Accepted:    317.5K
 * Total Submissions: 913.1K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

bool isInDictionary(const vector<string>& wordDict, const string& s)
{
   for (const auto& word : wordDict) {
      if (word == s) return true;
   }
   return false;
}

bool wordBreak(string s, vector<string>& wordDict) 
{
   if (s.empty()) return true;
   if (wordDict.empty()) return false;

   vector<bool> table(s.size(), false);
   for (size_t i = 0; i < s.size(); ++i) {
      if (i == 0 || table[i - 1]) {
         for (const auto& word : wordDict) {
            const size_t len = word.size();
            if (i + len <= s.size() && word == s.substr( i, len )) {
               table[i + len - 1] = true;
            }
         }
      }
   }
   return table.back();
}

int main()
{
   const string s("catsanddog");
   vector<string> word_dict = {
      "cats", "dog", "sand", "and", "cat"
   };
   cout << (wordBreak( s, word_dict ) ? "true" : "false") << endl;
   return 0;
}