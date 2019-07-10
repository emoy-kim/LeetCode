/*
 * https://leetcode.com/problems/island-perimeter/
 */

#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) 
{
   const int rows = grid.size();
   const int cols = grid[0].size();
   int perimeter = 0;
   for (int j = 0; j < rows; ++j) {
      for (int i = 0; i < cols; ++i) {
          if (grid[j][i] == 0) continue;
          if (j == 0 || grid[j - 1][i] == 0) perimeter++;
          if (j == rows - 1 || grid[j + 1][i] == 0) perimeter++;
          if (i == 0 || grid[j][i - 1] == 0) perimeter++;
          if (i == cols - 1 || grid[j][i + 1] == 0) perimeter++;
      }
   }
   return perimeter;
}

int main()
{
   vector<vector<int>> grid = {
      { 0, 1, 0, 0 },
      { 1, 1, 1, 0 },
      { 0, 1, 0, 0 },
      { 1, 1, 0, 0 }
   };
   cout << islandPerimeter( grid ) << endl;
}