/*
 * https://leetcode.com/problems/min-cost-climbing-stairs/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) 
{
   const int size = static_cast<int>(cost.size());
   vector<int> table(size, 0);
   table[0] = cost[0];
   table[1] = cost[1];
   for (int i = 2; i < size; ++i) {
      table[i] = cost[i] + min( table[i - 1], table[i - 2] );   
   }

   return min( table[size - 1], table[size - 2] );
}

int main()
{
   vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
   cout << minCostClimbingStairs( cost ) << endl;
   return 0;
}