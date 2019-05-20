#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums) 
{
   if (nums.empty()) return 0;
   if (nums.size() == 1) return nums[0];

   vector<int> table(nums.size());
   table[0] = nums[0];
   table[1] = max( table[0], nums[1] );
   for (size_t i = 2; i < table.size(); ++i) {
      table[i] = max( table[i - 1], nums[i] + table[i - 2] );
   }
   return table.back();
}