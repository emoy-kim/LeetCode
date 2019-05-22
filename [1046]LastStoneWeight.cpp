/*
 * https://leetcode.com/problems/last-stone-weight/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lastStoneWeight(vector<int>& stones) 
{
   while (stones.size() > 1) {
      sort( stones.begin(), stones.end(), greater<int>() );
      const int x = stones[0];
      const int y = stones[1];
      stones.erase( stones.begin(), stones.begin() + 2 );
      if (x != y) {
         stones.push_back( abs( x - y ) );
      }
   }
   return stones.empty() ? 0 : stones[0];
}

int main()
{
   vector<int> stones = { 1, 1 };
   cout << lastStoneWeight( stones ) << endl;
   return 0;
}