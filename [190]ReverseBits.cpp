/*
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (29.20%)
 * Total Accepted:    155K
 * Total Submissions: 530.8K
 * Testcase Example:  '    43261596 (00000010100101000001111010011100)'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * Example:
 * 
 * 
 * Input: 43261596
 * Output: 964176192
 * Explanation: 43261596 represented in binary as
 * 00000010100101000001111010011100, 
 * return 964176192 represented in binary as
 * 00111001011110000010100101000000.
 * 
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */

#include <iostream>
#include <vector>

using namespace std;

uint32_t reverseBits(uint32_t n) 
{
   uint32_t result = 0;
   for (int i = 0; i < 16; ++i) {
      int r = (n << (31 - i)) >> 31;
      int l = (n << i) >> 31;
      result |= r << (31 - i);
      result |= l << i;
   }
   return result;
}