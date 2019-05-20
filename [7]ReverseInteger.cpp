/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.43%)
 * Total Accepted:    479.2K
 * Total Submissions: 2M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int reverse(int x) 
{
   const bool sign = x < 0;

   int abs_x = abs( x );

   vector<int> digits;
   while ( abs_x != 0 ) {
      digits.push_back( abs_x % 10 );
      abs_x /= 10;
   }
   // 1534236469
   int reversed = 0;
   const int digit_num = digits.size();
   for (size_t i = 0; i < digits.size(); ++i) {
      reversed += static_cast<int>(digits[i] * pow( 10, digit_num - i - 1 ));
   }

   if (reversed < 0) return 0;

   int check = reversed;
   vector<int> check_digits;
   while ( check != 0 ) {
      check_digits.push_back( check % 10 );
      check /= 10;
   }
   for (size_t i = 0; i < check_digits.size(); ++i) {
      if (check_digits[i] != digits[digit_num - i - 1])
          return 0;
   }

   if (sign) reversed = -reversed;

   return reversed;
}