/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.08%)
 * Total Accepted:    213.5K
 * Total Submissions: 665.5K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) 
{
   int len = 0;
   for (int i = s.length() - 1; i >= 0; --i) {
      if (s[i] == ' ') {
          if (len == 0) continue;
          break;
      }
      len++;
   }
   return len;
}