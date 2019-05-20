/*
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (36.92%)
 * Total Accepted:    134.4K
 * Total Submissions: 364.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 */

#include <iostream>

using namespace std;

int trailingZeroes(int n) 
{
   int num = 0;
   int base = 5;
   const int overflow = INT_MAX / 5;
   while (n >= base) {
      num += n / base;
      if (base > overflow) break;
      base *= 5;
   }
   return num;
}