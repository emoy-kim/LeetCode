/*
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (43.90%)
 * Total Accepted:    32.5K
 * Total Submissions: 74.1K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */

#include <iostream>
#include <string>

using namespace std;

string convertToBase7(int num) 
{
   const bool sign = num < 0;

   int abs_num = abs( num );
   string result;

   while (abs_num >= 7) {
      result.insert( 0, to_string( abs_num % 7 ) );
      abs_num /= 7;
   }
   result.insert( 0, to_string( abs_num ) );

   if (sign) result.insert( 0, "-" );
   return result;       
}