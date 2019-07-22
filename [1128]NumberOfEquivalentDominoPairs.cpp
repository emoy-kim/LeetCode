/*
 * https://leetcode.com/problems/number-of-equivalent-domino-pairs/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) 
{
   int equal_num = 0;
   unordered_map<int, int> table;
   for (const auto& range : dominoes) {
      equal_num += table[min( range[0], range[1] ) * 10 + max( range[0], range[1] )]++;
   }
   return equal_num;
}

int main()
{
   vector<vector<int>> dominoes = { { 1,2 }, { 2,1 }, { 3,4 }, { 5,6 } };
   cout << numEquivDominoPairs( dominoes ) << endl;
   return 0;
}