/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.93%)
 * Total Accepted:    324.4K
 * Total Submissions: 1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
   string result;
   int length = INT_MAX;
   for (size_t i = 0; i < strs.size(); ++i) {
      if (length > strs[i].length()) {
          length = strs[i].length();
      }
   }
   if (length == INT_MAX) return result;

   for (int i = 0; i < length; ++i) {
      const char val = strs[0][i];
      for (size_t j = 1; j < strs.size(); ++j) {
          if (val != strs[j][i]) {
              return result;
          }
      }
      result += val;
   }
   return result;
}