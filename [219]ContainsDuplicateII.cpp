#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
   if (nums.size() <= 1) return false;

   const int len = nums.size();
   for (int i = 0; i < len - 1; ++i) {
      const int end = min( i + k, len - 1 );
      for (int j = i; j <= end; ++j) {
          if (i == j) continue;
          if (nums[i] == nums[j]) return true;
      }
   }
   return false;
}