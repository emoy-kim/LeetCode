/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 * 
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * 
 * Example 1:
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * Example 2:
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) 
{
   vector<string> summary;
   if (nums.empty()) return summary;

   int prev = nums[0];
   summary.push_back( to_string( prev ) );

   for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == prev + 1) {   
         do {
            prev = nums[i];
            i++;
         }
         while (i < nums.size() && nums[i] == prev + 1);

         i--;
         summary.back() += "->" + to_string( nums[i] );
      }
      else {
         summary.push_back( to_string( nums[i] ) );
      }
      prev = nums[i];
   }
   return summary;
}

int main()
{
   vector<int> nums = { 0,2,3,4,6,8,9 };
   vector<string> summary = summaryRanges( nums );
   for (const auto& s : summary) {
      cout << s.c_str() << " ";
   }
   cout << endl;
   return 0;
}