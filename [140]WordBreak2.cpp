/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (26.93%)
 * Total Accepted:    152.5K
 * Total Submissions: 565.9K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
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
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* Time Limit Exceed
 * 
vector<string> wordBreak(string s, vector<string>& wordDict) 
{
   if (s.empty()) return vector<string>();
   if (wordDict.empty()) return vector<string>();

   vector<bool> table(s.size(), false);
   unordered_map<int, vector<string>> mapper;
   for (size_t i = 0; i < s.size(); ++i) {
      if (i == 0 || table[i - 1]) {
         vector<string> initial = mapper[i - 1];
         if (initial.empty()) initial.emplace_back( "" );

         for (const auto& word : wordDict) {
            const size_t len = word.size();
            if (i + len <= s.size() && word == s.substr( i, len )) {
               const int pos = i + len - 1;
               table[pos] = true;
               for (auto& l : initial) {
                  mapper[pos].push_back( l + word + " " );
               }
            }
         }
      }
   }

   vector<string> list = mapper[s.size() - 1];
   if (!list.empty()) {
      for (auto& l : list) {
         l.resize( l.size() - 1 );
      }
   }
   sort( list.begin(), list.end() );
   return list;
}
*/

vector<string> findList(const string& s, vector<string>& wordDict, unordered_map<string, vector<string>>& mapper)
{
   if (mapper.find( s ) != mapper.end()) return mapper[s];

   vector<string> list;
   if (find( wordDict.begin(), wordDict.end(), s ) != wordDict.end()) list.push_back( s );
   for (size_t i = 1; i < s.length(); ++i) {
      string sub = s.substr( i );
      if (find( wordDict.begin(), wordDict.end(), sub ) != wordDict.end()) {
         vector<string> prev = findList( s.substr( 0, i ), wordDict, mapper );
         for (const auto& l : prev) {
            list.push_back( l + " " + sub );
         }
      }
   }
   mapper[s] = list;
   return list;
}

vector<string> wordBreak(string s, vector<string>& wordDict) 
{
   unordered_map<string, vector<string>> mapper;
   return findList( s, wordDict, mapper );
}

int main()
{
   const string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
   vector<string> word_dict = {
      "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"
   };

   const vector<string> list = wordBreak( s, word_dict );
   for (const auto& sentence : list) {
      cout << sentence << "," << endl;
   }
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
   // "pineapplepenapple"\n["apple","pen","applepen","pine","pineapple"]
   // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"\n["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
>>>>>>> 251d841b1b9138cec531f5dfa4719c5665907861
>>>>>>> 10332eeded7a0647838e638d7072ddfd531b8ec0
   return 0;
}