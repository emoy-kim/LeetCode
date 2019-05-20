/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (35.71%)
 * Total Accepted:    231.6K
 * Total Submissions: 648.5K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) 
{
   if (a.length() < b.length()) swap( a, b );

   string result;
   const int a_len = a.length();
   const int b_len = b.length();
   const int diff_len = a_len - b_len;
   int carry = 0;
   for (int i = a_len - 1; i >= 0; --i) {
      const int a_val = a[i] - '0';
      int b_val = 0;
      if (diff_len <= i) {
          b_val = b[i - diff_len] - '0';    
      }

      int sum = a_val + b_val + carry;
      if (sum >= 2) {
          sum -= 2;
          carry = 1;
      }
      else carry = 0;
      result.insert( 0, to_string( sum ) );
   }
   if (carry != 0) {
      result.insert( 0, to_string( carry ) );            
   }

   return result;
}