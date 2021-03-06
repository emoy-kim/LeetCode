﻿/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (22.53%)
 * Total Accepted:    167.9K
 * Total Submissions: 745.2K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
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
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(string s, string p) 
{
   const int s_len = s.size();
   const int p_len = p.size();
   vector<vector<bool>> table(s_len + 1, vector<bool>(p_len + 1, false));
   table[0][0] = true;
   for (int i = 1; i <= p_len; ++i) {
      if (p[i - 1] == '*') table[0][i] = table[0][i - 1];
   }

   for (int j = 1; j <= s_len; ++j) {
      for (int i = 1; i <= p_len; ++i) {
         const bool match = p[i - 1] == '?' || s[j - 1] == p[i - 1]; 
         if (p[i - 1] == '*') {
            table[j][i] = table[j][i - 1] || table[j - 1][i];
         }
         else table[j][i] = match && table[j - 1][i - 1];
      }
   }
   return table[s_len][p_len];
}

int main()
{
   const string s("ho");
   const string p("**ho");
   cout << (isMatch( s, p ) ? "true" : "false") << endl;
}