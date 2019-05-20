﻿/*
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (43.05%)
 * Total Accepted:    190.4K
 * Total Submissions: 442.2K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 */

#include <iostream>
#include <set>

using namespace std;

bool isHappy(int n) {
   set<int> dic;
   while (n != 1) {
      int d = n;
      int sum = 0;
      while (d) {
          int digit = d % 10;
          sum += digit * digit;
          d /= 10;
      }
      
      if (dic.find( sum ) == dic.end()) dic.insert( sum );
      else return false;

      n = sum;
   }
   return true;
}