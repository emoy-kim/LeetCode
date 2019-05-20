/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (38.37%)
 * Total Accepted:    393.6K
 * Total Submissions: 1M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) 
{
   if (x < 0) return false;

   int forward = x;
   vector<int> forward_digits;
   while (forward != 0) {
      forward_digits.push_back( forward % 10 );
      forward /= 10;
   }

   int backward = 0;
   for (size_t i = 0; i < forward_digits.size(); ++i) {
      backward += static_cast<int>(forward_digits[i] * pow( 10, forward_digits.size() - i - 1 ));
   }

   return backward == x;
}