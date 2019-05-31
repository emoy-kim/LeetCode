/*
 * https://leetcode.com/problems/last-stone-weight-ii/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lastStoneWeightII(vector<int>& stones) 
{
   int total_sum = 0;
   for (const auto& n : stones) {
      total_sum += n;
   }

   vector<vector<bool>> table(total_sum + 1, vector<bool>(stones.size() + 1));
   for (auto i : table[0]) {
      i = true;
   }

   int max_half_sum = 0;
   const int half = total_sum / 2;
   for (int s = 1; s <= half; ++s) {
      for (size_t i = 0; i < stones.size(); ++i) {
         if (table[s][i] || stones[i] <= s && table[s - stones[i]][i]) {
            table[s][i + 1] = true;
            max_half_sum = max( max_half_sum, s );
         }
      }
   }
   return total_sum - 2 * max_half_sum;
}

int main()
{
   vector<int> stones = { 2,7,4,1,8,1 };
   cout << lastStoneWeightII( stones ) << endl;
   return 0;
}