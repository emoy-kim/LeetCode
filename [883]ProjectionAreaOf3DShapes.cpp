/*
 * https://leetcode.com/problems/projection-area-of-3d-shapes/
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int projectionArea(vector<vector<int>>& grid) 
{
   const int rows = grid.size();
   const int cols = grid[0].size();
   int area = 0;
   vector<int> max_cols(cols, -1);
   for (int j = 0; j < rows; ++j) {
      int max_row = -1;
      for (int i = 0; i < cols; ++i) {
          if (max_row < grid[j][i]) max_row = grid[j][i];
          if (max_cols[i] < grid[j][i]) max_cols[i] = grid[j][i];
          if (grid[j][i] != 0) area++;
      }
      area += max_row;
   }
   area = accumulate( max_cols.begin(), max_cols.end(), area );
   return area;
}

int main()
{
   vector<vector<int>> grid = {
      { 2, 2, 2 }, { 2, 1, 2 }, { 2, 2, 2 }
   };
   cout << projectionArea( grid ) << endl;
   return 0;
}