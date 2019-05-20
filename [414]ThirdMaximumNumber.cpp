#include <iostream>
#include <vector>

using namespace std;

int thirdMax(vector<int>& nums) 
{
   vector<int> maxs;
   maxs.push_back( nums[0] );
   for (size_t i = 1; i < nums.size(); ++i) {
      for (size_t j = 0; j < maxs.size(); ++j) {
          if (nums[i] == maxs[j]) break;
          if (nums[i] > maxs[j]) {
              maxs.insert( maxs.begin() + j, nums[i] );
              break;
          }
          if (j == maxs.size() - 1) maxs.push_back( nums[i] );
      }
      if (maxs.size() > 3) maxs.erase( maxs.end() - 1 );
   }

   if (maxs.size() == 3) return maxs[2];
   return maxs[0];
}