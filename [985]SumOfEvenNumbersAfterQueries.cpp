/*
 * https://leetcode.com/problems/sum-of-even-numbers-after-queries/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) 
{
   int s = 0;
   for (const auto& i : A) {
      if ((i & 1) == 0) s += i;
   }

   vector<int> sums;
   for (const auto& q : queries) {
      const int before = A[q[1]];
      A[q[1]] += q[0];
      
      if ((before & 1) == 1 && (q[0] & 1) == 1) s += A[q[1]];
      else if ((before & 1) == 0 && (q[0] & 1) == 0) s += q[0];
      else if ((before & 1) == 0 && (q[0] & 1) == 1) s -= before;

      sums.push_back( s );
   }
   return sums;
}

int main()
{
   vector<int> A = { 1, 2, 3, 4 };
   vector<vector<int>> queries = {
      { 1, 0 }, { -3, 1 }, { -4, 0 }, { 2, 3 }
   };
   vector<int> sums = sumEvenAfterQueries( A, queries );
   for (const auto& s : sums) {
      cout << s << " ";
   }
   cout << endl;
   return 0;
}