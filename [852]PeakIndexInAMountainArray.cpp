/*
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/
 */

#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& A) 
{
   int max_val = -1, max_index = -1;
   for (size_t i = 0; i < A.size(); ++i) {
      if (max_val < A[i]) {
          max_val = A[i];
          max_index = i;
      }
   }
   return max_index;    
}

int main()
{
   vector<int> A = { 1, 3, 1, 0 };
   cout << peakIndexInMountainArray( A ) << endl;
   return 0;
}