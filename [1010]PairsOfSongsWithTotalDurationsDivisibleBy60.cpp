/*
 * https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* slow version
int numPairsDivisibleBy60(vector<int>& time) 
{
   unordered_map<int, vector<int>> table;

   int pair_num = 0;
   const int n = time.size();
   for (int i = 0; i < n - 1; ++i) {
      auto it = table.find( time[i] );
      if (table.find( time[i] ) == table.end()) {
         vector<int> index_set;
         for (size_t j = i + 1; j < n; ++j) {
            if ((time[i] + time[j]) % 60 == 0) {
               pair_num++;
               index_set.push_back( j );
            }
         }
         table[time[i]] = index_set;
      }
      else {
         for (const auto& k : it->second) {
            if (k > i) pair_num++;
         }
      }
   }
   return pair_num;
}
*/

// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/256722/C%2B%2B-5-lines-two-sum
int numPairsDivisibleBy60(vector<int>& time) 
{
   int res = 0;
   vector<int> m(60);
   for (auto t : time) {
      res += m[(60 - t % 60) % 60];
      ++m[t % 60];
   }
   return res;
}

int main()
{
   vector<int> time = { 60,60,60 };
   cout << numPairsDivisibleBy60( time ) << endl;
   return 0;
}