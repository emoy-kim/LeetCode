/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (42.04%)
 * Total Accepted:    290.9K
 * Total Submissions: 691.9K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int climbStairs(int n) 
{
   if (n == 1) return 1;
   if (n == 2) return 2;

   int ways;
   int two_prev = 1;
   int one_prev = 2;
   for (int i = 2; i < n; ++i) {
      ways = two_prev + one_prev;
      two_prev = one_prev;
      one_prev = ways;
   }
   return ways;
}