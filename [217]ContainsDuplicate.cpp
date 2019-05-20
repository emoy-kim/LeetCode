#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
   if (nums.size() <= 1) return false;

   sort( nums.begin(), nums.end() );
   for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) return true;
   }
   return false;
}