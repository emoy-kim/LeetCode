/*
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (57.37%)
 * Total Accepted:    363.8K
 * Total Submissions: 634K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int singleNumber(vector<int>& nums) 
{
   set<int> dic;
   int sum = 0;
   int only_once = 0;
   for (size_t i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (dic.find( nums[i] ) == dic.end()) {
          dic.insert( nums[i] );
          only_once += nums[i];
      }
   }
   return 2 * only_once - sum;
}