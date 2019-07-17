/*
 * https://leetcode.com/problems/transpose-matrix/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& A) 
{
   const int rows = A.size();
   const int cols = A[0].size();
   vector<vector<int>> B(cols, vector<int>(rows));
   for (int j = 0; j < rows; ++j) {
      for (int i = 0; i < cols; ++i) {
          B[i][j] = A[j][i];
      }
   }
   return B;
}

int main()
{
   vector<vector<int>> A = {
      { 1, 2, 3 }, { 4, 5, 6 }
   };
   vector<vector<int>> B = transpose( A );
   for (size_t j = 0; j < B.size(); ++j) {
      for (size_t i = 0; i < B[0].size(); ++i) {
         cout << B[j][i] << " ";
      }
      cout << endl;
   }
   return 0;
}