/*
 * [191] Number of 1 Bits
 *
 * https://leetcode.com/problems/number-of-1-bits/description/
 *
 * algorithms
 * Easy (40.91%)
 * Total Accepted:    222.7K
 * Total Submissions: 544.3K
 * Testcase Example:  '           0 (00000000000000000000000000000000)'
 *
 * Write a function that takes an unsigned integer and returns the number of
 * '1' bits it has (also known as the Hamming weight).
 * 
 * Example 1:
 * 
 * 
 * Input: 11
 * Output: 3
 * Explanation: Integer 11 has binary representation
 * 00000000000000000000000000001011 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 128
 * Output: 1
 * Explanation: Integer 128 has binary representation
 * 00000000000000000000000010000000
 * 
 * 
 */

#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
   int num = 0;
   while (n) {
      num += n & 1;
      n >>= 1;
   }
   return num;
}