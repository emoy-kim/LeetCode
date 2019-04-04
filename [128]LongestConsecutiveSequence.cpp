/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (41.18%)
 * Total Accepted:    197.2K
 * Total Submissions: 478.6K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) 
{
   unordered_map<int, int> map;
   for (const auto& num : nums) {
      if (map[num] != 0) continue;

      const int left_consecutive = map[num - 1];
      const int right_consecutive = map[num + 1];
      if (left_consecutive == 0 && right_consecutive == 0) {
         map[num] = 1;
      }
      else if (left_consecutive == 0) {
         map[num] = map[num + right_consecutive] = right_consecutive + 1;
      }
      else if (right_consecutive == 0) {
         map[num] = map[num - left_consecutive] = left_consecutive + 1;
      }
      else {
         map[num] = map[num - left_consecutive] = map[num + right_consecutive] = 
            left_consecutive + right_consecutive + 1;
      }
   }

   int max = 0;
   for (auto it = map.begin(); it != map.end(); ++it) {
      if (it->second > max) max = it->second;
   }
   return max;
}

int main()
{
   vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };
   cout << longestConsecutive( nums ) << endl;
   return 0;
}