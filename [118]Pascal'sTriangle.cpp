/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (42.56%)
 * Total Accepted:    201.3K
 * Total Submissions: 473K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) 
{
   vector<vector<int>> result;
   if (numRows == 0) return result;

   result.push_back( vector<int>{1} );
   if (numRows == 1) return result;

   for (int i = 2; i <= numRows; ++i) {
      vector<int> rows(i);
      rows[0] = rows[i - 1] = 1;
      for (int j = 1; j < i - 1; ++j) {
          rows[j] = result.back()[j - 1] + result.back()[j];
      }
      result.push_back( rows );
   }
   return result;
}