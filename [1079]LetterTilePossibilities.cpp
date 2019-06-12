/*
 * https://leetcode.com/problems/letter-tile-possibilities/
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int calculatePermutation(const string& sequence)
{
   static vector<int> factorials = { 1, 1, 2, 6, 24, 120, 720, 5040 };
   int permutation = factorials[sequence.length()];

   vector<int> nums(26, 0);
   for (const auto& c : sequence) nums[c - 'A']++;
   for (const auto& n : nums) {
      if (n == 0) continue;
      permutation /= factorials[n];
   }
   return permutation;
}

int dfs(unordered_set<string>& table, const string& sequence, const string& tiles, const size_t& index)
{
   if (index >= tiles.length()) {
      const bool is_new = table.insert( sequence ).second;
      return is_new ? calculatePermutation( sequence ) : 0;
   }
   return 
      dfs( table, sequence, tiles, index + 1 ) + 
      dfs( table, sequence + tiles[index], tiles, index + 1 );
}

int numTilePossibilities(string tiles) 
{
   unordered_set<string> table;
   sort( tiles.begin(), tiles.end() );
   return dfs( table, "", tiles, 0 ) - 1;
}

int main()
{
   const string tiles = "AABA";
   cout << numTilePossibilities( tiles ) << endl;
   return 0;
}