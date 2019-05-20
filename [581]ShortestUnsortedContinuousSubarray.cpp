#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) 
{
   if (nums.empty()) return 0;

   vector<int> copied = nums;
   sort( copied.begin(), copied.end() );

   int start = -1;
   for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] != copied[i]) {
          start = i;
          break;
      }
   }

   if (start == -1) return 0;

   int end = nums.size() - 1;
   for (size_t i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] != copied[i]) {
          end = i;
          break;
      }
   }

   return end - start + 1;
}