/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (40.28%)
 * Total Accepted:    166.4K
 * Total Submissions: 413K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

uint64_t nCk(int n, int k)
{
   if (k == 0) return 1;
   if (k * 2 > n) k = n-k;

   uint64_t r = 1;
   for (uint64_t d = 1LL; d <= k; ++d) {
      r *= n--;
      r /= d;
   }
   return r;
}

vector<int> getRow(int rowIndex) {
   if (rowIndex == 0) return vector<int>{ 1 };
   if (rowIndex == 1) return vector<int>{ 1, 1 };

   const int mid = rowIndex / 2;
   vector<int> result(rowIndex + 1);
   for (int i = 0; i <= mid; ++i) {
      result[i] = nCk( rowIndex, i );
   }
   for (int i = mid + 1; i <= rowIndex; ++i) {
      result[i] = result[rowIndex - i];
   }
   return result;
}