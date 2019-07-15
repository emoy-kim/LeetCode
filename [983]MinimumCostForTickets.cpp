/*
 * https://leetcode.com/problems/minimum-cost-for-tickets/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) 
{
   unordered_set<int> travel_days(days.begin(), days.end());

   vector<int> cost_table(366, 0);
   for (int i = 1; i <= 365; ++i) {
      if (travel_days.find( i ) != travel_days.end()) {
          cost_table[i] = min( 
              cost_table[i - 1] + costs[0],
              min( 
                  cost_table[max( 0, i - 7 )] + costs[1], 
                  cost_table[max( 0, i - 30 )] + costs[2] 
              )
          );
      }
      else cost_table[i] = cost_table[i - 1];
   }
   return cost_table.back();
}

int main()
{
   vector<int> days = { 1,2,3,4,5,6,7,8,9,10,30,31 };
   vector<int> costs = { 2,7,15 };
   cout << mincostTickets( days, costs ) << endl;
   return 0;
}