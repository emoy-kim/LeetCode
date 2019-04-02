/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.18%)
 * Total Accepted:    222.8K
 * Total Submissions: 738.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) 
{
   if (nums.size() <= 1) return;

   const int size = nums.size();
   for (int i = size - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
         int greater = size - 1;
         for (; greater >= 0; --greater) {
            if (nums[i] < nums[greater]) break;
         }
         swap( nums[i], nums[greater] );
         sort( nums.begin() + i + 1, nums.end() );
         return;
      }
   }
   sort( nums.begin(), nums.end() );
}

int main()
{
   vector<int> nums = { 1, 2, 10, 3 };

   vector<int> ground_truth = nums;
   next_permutation( ground_truth.begin(), ground_truth.end() );
   for (const auto& n : ground_truth) {
      cout << n << " ";
   }
   cout << endl;

   nextPermutation( nums );
   for (const auto& n : nums) {
      cout << n << " ";
   }
   cout << endl;
   return 0;
}