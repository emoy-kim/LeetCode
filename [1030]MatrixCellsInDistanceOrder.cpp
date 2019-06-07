/*
 * https://leetcode.com/problems/matrix-cells-in-distance-order/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
{
   vector<vector<int>> sorted(R * C, vector<int>(2));
   for (int j = 0; j < R; ++j) {
      for (int i = 0; i < C; ++i) {
         sorted[j * C + i][0] = j;
         sorted[j * C + i][1] = i;
      }
   }
   sort( sorted.begin(), sorted.end(), 
      [&](const vector<int>& v1, const vector<int>& v2)
      {
         const int d1 = abs( v1[0] - r0 ) + abs( v1[1] - c0 );
         const int d2 = abs( v2[0] - r0 ) + abs( v2[1] - c0 );
         return d1 < d2;
      }
   );
   return sorted;
}

int main()
{
   vector<vector<int>> sorted = allCellsDistOrder( 2, 3, 1, 2 );
   for (const auto& i : sorted) {
      cout << "[" << i[0] << ", " << i[1] << "] ";
   }
   cout << endl;
   return 0;
}