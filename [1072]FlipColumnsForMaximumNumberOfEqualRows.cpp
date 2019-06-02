/*
 * https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
{
   int rows = matrix.size();
   const int cols = matrix[0].size();

   int max_equal_rows = 0;
   while (rows > max_equal_rows) {
      vector<vector<int>> not_matched;
      for (int j = 1; j < rows; ++j) {
         const int v = matrix[0][0] ^ matrix[j][0];
         for (int i = 1; i < cols; ++i) {
            if (v != (matrix[0][i] ^ matrix[j][i])) {
               not_matched.push_back( matrix[j] );
               break;
            }
         }
      }
      max_equal_rows = max( max_equal_rows, rows - static_cast<int>(not_matched.size()) );
      rows = not_matched.size();
      matrix = not_matched;
   }
   return max_equal_rows;
}

int main()
{
   vector<vector<int>> matrix = {
      { 0, 0, 0 },
      { 0, 0, 1 },
      { 1, 1, 0 }
   };
   cout << maxEqualRowsAfterFlips( matrix ) << endl;
   return 0;
}