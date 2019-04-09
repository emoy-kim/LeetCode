/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (40.97%)
 * Total Accepted:    226.9K
 * Total Submissions: 553.7K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array nums, where nums[i] ¡Á nums[i+1], find a peak element
 * and return its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that nums[-1] = nums[n] = -¡Ä.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2, 
 * or index number 5 where the peak element is 6.
 * 
 * 
 * Note:
 * 
 * Your solution should be in logarithmic complexity.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums)
{
   int left = 0;
   int right = nums.size() - 1;
   while (left + 1 < right) {
      const int mid = (right - left) / 2 + left;
      if (nums[mid] < nums[mid + 1]) left = mid;
      else right = mid;
   }
   return nums[left] < nums[right] ? right : left;
}

int main()
{
   vector<int> nums = { 1,2,1,3,5,6,4 };
   cout << findPeakElement( nums ) << endl;
   return 0;
}