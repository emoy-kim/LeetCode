/*
 * https://leetcode.com/problems/sort-array-by-parity-ii/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) 
{
   int e = 0, o = 1;
   const int size = A.size();
   while (true) {
      while (o < size && (A[o] & 1) == 1) { o += 2; }
      while (e < size && (A[e] & 1) == 0) { e += 2; }
      if (o < size && e < size) { swap( A[o], A[e] ); }
      else break;
   }
   return A;
}

int main()
{
   vector<int> A = { 4, 2, 5, 7 };
   vector<int> sorted = sortArrayByParityII( A );
   for (const auto& i : sorted) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}