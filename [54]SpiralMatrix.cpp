/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (29.93%)
 * Total Accepted:    219.2K
 * Total Submissions: 731.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
   if (matrix.empty()) return vector<int>();

   const int row = matrix.size();
   const int col = matrix[0].size();
   int col_start_forward = 0, col_end_forward = col - 1;
   int row_start_downward = 1, row_end_downward = row - 1;
   int col_start_backward = col - 2, col_end_backward = 0;
   int row_start_upward = row - 2, row_end_upward = 1;

   vector<int> spiral;
   int x, y = 0;
   const size_t size = row * col;
   while (true) {
      for (x = col_start_forward; x <= col_end_forward; ++x) {
         spiral.push_back( matrix[y][x] );
      }
      if (spiral.size() == size) break;
      x = col_end_forward;

      for (y = row_start_downward; y <= row_end_downward; ++y) {
         spiral.push_back( matrix[y][x] );
      }
      if (spiral.size() == size) break;
      y = row_end_downward;

      for (x = col_start_backward; x >= col_end_backward; --x) {
         spiral.push_back( matrix[y][x] );
      }
      if (spiral.size() == size) break;
      x = col_end_backward;

      for (y = row_start_upward; y >= row_end_upward; --y) {
         spiral.push_back( matrix[y][x] );
      }
      if (spiral.size() == size) break;
      y = row_end_upward;

      col_start_forward++;
      col_end_forward--;
      row_start_downward++;
      row_end_downward--;
      col_start_backward--;
      col_end_backward++;
      row_start_upward--;
      row_end_upward++;
   }
   return spiral;
}

int main()
{
   vector<vector<int>> matrix = {
      { 1, 2, 3, 4, 5 },
      { 1, 2, 3, 4, 5 },
   };
   const vector<int> spiral = spiralOrder( matrix );
   for (const auto& val : spiral) {
      cout << val << " ";
   }
   cout << endl;
   return 0;
}