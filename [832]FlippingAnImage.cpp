/*
 * https://leetcode.com/problems/flipping-an-image/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
{
   vector<vector<int>> flipped;
   for (const auto& row : A) {
      const int rows = row.size();
      flipped.emplace_back();
      for (int i = rows - 1; i >= 0; --i) {
         flipped.back().push_back( row[i] ? 0 : 1 );
      }
   }
   return flipped;
}

int main()
{
   vector<vector<int>> A = {
      { 1, 1, 0 }, { 1, 0, 1 }, { 0, 0, 0 }
   };
   vector<vector<int>> flipped = flipAndInvertImage( A );
   for (const auto& row : flipped) {
      for (const auto& i : row) {
         cout << i << " ";
      }
      cout << endl;
   }
   cout << endl;
   return 0;
}