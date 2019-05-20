/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (29.50%)
 * Total Accepted:    270.7K
 * Total Submissions: 917.5K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int mySqrt(int x) 
{
   const double xd = static_cast<double>(x);

   int a = 0;
   while (static_cast<double>(a) * static_cast<double>(a) <= xd) {
      a++;
   }
   return a - 1;
}