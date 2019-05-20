#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int findPairs(vector<int>& nums, int k) 
{
   if (nums.empty()) return 0;

   sort( nums.begin(), nums.end() );

   int count = 0;
   unordered_set<int> dic;
   for (size_t i = 0; i < nums.size() - 1; ++i) {
      const int a = nums[i];
      if (dic.find( a ) != dic.end()) continue;
      
      for (size_t j = i + 1; j < nums.size(); ++j) {
          const int b = nums[j];
          if (a + k == b) {
              count++;
              dic.insert( a );
              break;
          }
          if (a + k < b) break;
      }
   }
   return count;
}