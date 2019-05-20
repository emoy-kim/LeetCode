/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (41.22%)
 * Total Accepted:    368.1K
 * Total Submissions: 892.9K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) 
{
   int max_val = *max_element( nums.begin(), nums.end() );
   if (max_val < 0) return max_val;

   int max_sum = 0, sum = 0, total_sum = 0;
   for (size_t i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      total_sum += nums[i];
      if (sum < 0) sum = 0;
      max_sum = max( max_sum, sum );
   }
   return max_sum;
}