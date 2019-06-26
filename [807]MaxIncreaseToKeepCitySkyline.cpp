/*
 * https://leetcode.com/problems/max-increase-to-keep-city-skyline/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
  const int rows = grid.size();
  const int cols = grid[0].size();
  vector<int> horizontal(grid.size(), 0), vertical(grid[0].size(), 0);
  for (int j = 0; j < rows; ++j) {
      for (int i = 0; i < cols; ++i) {
          horizontal[j] = max( horizontal[j], grid[j][i] );
          vertical[i] = max( vertical[i], grid[j][i] );
      }
  }
  
  int height_sum = 0;
  for (int j = 0; j < rows; ++j) {
      for (int i = 0; i < cols; ++i) {
          height_sum += min( horizontal[j], vertical[i] ) - grid[j][i];
      }
  }
  return height_sum;
}

int main()
{
   vector<vector<int>> grid = {
      { 3, 0, 8, 4 }, 
      { 2, 4, 5, 7 },
      { 9, 2, 6, 3 },
      { 0, 3, 1, 0 }
   };
   cout << maxIncreaseKeepingSkyline( grid ) << endl;
   return 0;
}