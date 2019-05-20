/*
 * [941] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (74.12%)
 * Total Accepted:    8K
 * Total Submissions: 10.8K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A) 
{
   vector<int> even_set, odd_set;
   for (size_t i = 0; i < A.size(); ++i) {
      if (A[i] & 1) odd_set.push_back( A[i] );
      else even_set.push_back( A[i] );
   }

   even_set.insert( even_set.end(), odd_set.begin(), odd_set.end() );
   return even_set;
}