/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (27.72%)
 * Total Accepted:    302.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */

#include <iostream>

using namespace std;

double myPow(double x, int n) 
{
   if (n == 0) return 1.0;
   if (x == 0.0 || x == 1.0) return x;
   if (n == numeric_limits<int>::min()) {
      const double sqrt = myPow( x, n >> 1 );
      return sqrt * sqrt;
   }

   if (n < 0) {
      x = 1.0 / x;
      n = -n;
   }

   const double sqrt = myPow( x, n >> 1 );
   const double pow = sqrt * sqrt;
   return (n & 1) != 0 ? pow * x : pow;
}

int main()
{
   const double x = 10.0;
   const int n = 100;
   cout << myPow( x, n ) << endl;
   return 0;
}