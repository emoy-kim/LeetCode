/*
 * https://leetcode.com/problems/delete-columns-to-make-sorted/
 */

#include <iostream>
#include <vector>

using namespace std;

int minDeletionSize(vector<string>& A) 
{
   int d_len = 0;
   const int len = A[0].length();
   for (int l = 0; l < len; ++l) {
      for (size_t i = 0; i < A.size() - 1; ++i) {
          if (A[i][l] > A[i + 1][l]) {
              d_len++;
              break;
          }
      }
   }
   return d_len;
}

int main()
{
   vector<string> A = { "cba", "daf", "ghi" };
   cout << minDeletionSize( A ) << endl;
   return 0;
}