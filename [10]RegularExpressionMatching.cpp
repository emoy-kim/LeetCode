/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.07%)
 * Total Accepted:    287.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p) 
{
   const int s_len = s.size();
   const int p_len = p.size();
   vector<vector<bool>> table(s_len + 1, vector<bool>(p_len + 1, false));
   table[s_len][p_len] = true;
   for (int j = s_len; j >= 0; --j) {
      for (int i = p_len - 1; i >= 0; --i) {
         const bool match = j < s_len && (p[i] == '.' || s[j] == p[i]); 
         if (i < p_len - 1 && p[i + 1] == '*') {
            table[j][i] = table[j][i + 2] || (match && table[j + 1][i]);
         }
         else table[j][i] = match && table[j + 1][i + 1];
      }
   }
   return table[0][0];
}

int main()
{
   const string s("aa");
   const string p("a*");
   cout << (isMatch( s, p ) ? "true" : "false") << endl;
   return 0;
}