/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (28.86%)
 * Total Accepted:    278.5K
 * Total Submissions: 964.8K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) 
{
   string compact;
   char to_lower = 'a' - 'A';
   for (int i = 0; i < s.length(); ++i) {
      if ('a' <= s[i] && s[i] <= 'z') compact.push_back( s[i] );
      else if ('A' <= s[i] && s[i] <= 'Z') compact.push_back( s[i] + to_lower );
      else if ('0' <= s[i] && s[i] <= '9') compact.push_back( s[i] );
   }

   int len = compact.length();
   for (int i = 0; i < len; ++i) {
      if (compact[i] != compact[len - i - 1]) return false;
   }
   return true;
}