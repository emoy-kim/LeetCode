/*
 * https://leetcode.com/problems/score-after-flipping-matrix/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matrixScore(vector<vector<int>>& A) 
{
   const int rows = A.size();
   const int cols = A[0].size();
   int sum = rows * (1 << (cols - 1));
   for (int i = 1; i < cols; ++i) {
      int one_nums = 0;
      for (int j = 0; j < rows; ++j) {
          if (A[j][i] == A[j][0]) one_nums++;
      }
      sum += max( one_nums, rows - one_nums ) * (1 << (cols - i - 1));
   }
   return sum;
}

int main()
{
   vector<vector<int>> A = { { 0, 0, 1, 1 }, { 1, 0, 1, 0 }, { 1, 1, 0, 0 } };
   cout << matrixScore( A ) << endl;
   return 0;
}