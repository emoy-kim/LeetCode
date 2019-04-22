/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (40.86%)
 * Total Accepted:    334.9K
 * Total Submissions: 815.6K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<char>>& grid, const int& i, const int& j, const int& col, const int& row)
{
   queue<pair<int, int>> visit;
   visit.push( make_pair( j, i ) );

   const int visited = 2;
   grid[j][i] = visited;

   while (!visit.empty()) {
      const pair<int, int> node = visit.front();
      const int x = node.second;
      const int y = node.first;
      visit.pop();

      if (x >= 1 && grid[y][x - 1] == 1) {
         visit.push( make_pair( y, x - 1 ) );
         grid[y][x - 1] = visited;
      }
      if (x < col - 1 && grid[y][x + 1] == 1) {
         visit.push( make_pair( y, x + 1 ) );
         grid[y][x + 1] = visited;
      }
      if (y >= 1 && grid[y - 1][x] == 1) {
         visit.push( make_pair( y - 1, x ) );
         grid[y - 1][x] = visited;
      }
      if (y < row - 1 && grid[y + 1][x] == 1) {
         visit.push( make_pair( y + 1, x ) );
         grid[y + 1][x] = visited;
      }
   }
}

int numIslands(vector<vector<char>>& grid) 
{
   const int row = grid.size();
   if (row == 0) return 0;

   const int col = grid[0].size();
   if (col == 0) return 0;

   int num = 0;
   for (int j = 0; j < row; ++j) {
      for (int i = 0; i < col; ++i) {
         if (grid[j][i] == 1) {
            bfs( grid, i, j, col, row );
            num++;
         }
      }
   }
   return num;
}

int main()
{
   vector<vector<char>> grid = {
      { 1, 1, 1, 1, 1 },
      { 0, 0, 1, 0, 0 },
      { 0, 0, 0, 0, 0 },
      { 1, 1, 1, 1, 1 }
   };
   cout << numIslands( grid ) << endl;
   return 0;
}