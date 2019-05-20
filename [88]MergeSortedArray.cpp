/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (33.28%)
 * Total Accepted:    273.5K
 * Total Submissions: 821.8K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
   nums1.resize( m );
   nums2.resize( n );
   nums1.insert( nums1.end(), nums2.begin(), nums2.end() );
   sort( nums1.begin(), nums1.end() );
}