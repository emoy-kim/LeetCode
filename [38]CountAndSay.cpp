/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (37.84%)
 * Total Accepted:    220.5K
 * Total Submissions: 582.7K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */

#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) 
{
   string result = "1";
   for (int i = 1; i < n; ++i) {
      string say;
      int repeat_num = 1;
      char val = result[0];
      for (int s = 1; s < result.length(); ++s) {
          if (val == result[s]) repeat_num++;
          else {
              say += to_string( repeat_num ) + val;
              val = result[s];
              repeat_num = 1;
          }
      }
      say += to_string( repeat_num ) + val;

      result = say;
   }
   return result;
}