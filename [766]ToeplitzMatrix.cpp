/*
 * https://leetcode.com/problems/toeplitz-matrix/
 */

#include <iostream>
#include <vector>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) 
{
   const int row = matrix.size();
   const int col = matrix[0].size();
   for (int j = 1; j < row; ++j) {
      for (int i = 1; i < col; ++i) {
         if (matrix[j][i] != matrix[j - 1][i - 1]) return false;
      }
   }
   return true;
}

int main()
{
   vector<vector<int>> matrix = {
      { 1, 2, 3, 4 },
      { 5, 1, 2, 3 },
      { 9, 5, 1, 2 },
      { 9, 9, 5, 1 }
   };
   cout << isToeplitzMatrix( matrix ) << endl;
   return 0;
}