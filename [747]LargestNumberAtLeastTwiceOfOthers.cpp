/*
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dominantIndex(vector<int>& nums) 
{
   const auto max_it = max_element( nums.begin(), nums.end() );
   const int max_val = *max_it;
   for (const auto& n : nums) {
      if (max_val != n && max_val < 2 * n) return -1;
   }
   return distance( nums.begin(), max_it );
}

int main()
{
   vector<int> nums = { 2, 1, 1, 4 };
   cout << dominantIndex( nums ) << endl;
   return 0;
}