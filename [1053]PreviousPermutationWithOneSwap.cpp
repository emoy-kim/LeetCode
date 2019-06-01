/*
 * https://leetcode.com/problems/previous-permutation-with-one-swap/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prevPermOpt1(vector<int>& A) 
{
   vector<int> prev(A);
   while (prev_permutation( prev.begin(), prev.end() )) {
      int different_num = 0;
      for (size_t i = 0; i < A.size(); ++i) {
         if (A[i] != prev[i]) different_num++;
         if (different_num > 2) break;
      }
      if (different_num == 2) return prev;
   }
   return A;
}

int main()
{
   vector<int> A = { 3,1,1,3 };
   vector<int> prev_permutation = prevPermOpt1( A );
   for (const auto& i : prev_permutation) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}