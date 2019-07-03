/*
 * https://leetcode.com/problems/squares-of-a-sorted-array/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& A) 
{
   for (auto& i : A) {
      i = i * i;
   }
   sort( A.begin(), A.end() );
   return A;
}

int main()
{
   vector<int> A = { -4, -1, 0, 3, 10 };
   vector<int> sorted = sortedSquares( A );
   for (const auto& n : sorted) {
      cout << n << " ";
   }
   cout << endl;
   return 0;
}