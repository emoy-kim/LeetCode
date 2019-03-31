/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.82%)
 * Total Accepted:    403K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
   const int total =  nums1.size() + nums2.size();

   int mid1;
   const int mid2 = total / 2;
   if ((total & 1) == 0) mid1 = mid2 - 1;
   else mid1 = mid2;

   unsigned int m_idx = 0;
   unsigned int n_idx = 0;
   double result = 0.0;
   for (int idx = 0; idx < total; ++idx) {
      int val;
      if (n_idx == nums2.size() || (m_idx != nums1.size() && nums1[m_idx] <= nums2[n_idx])) {
          val = nums1[m_idx];
          m_idx++;
      }
      else {
          val = nums2[n_idx];
          n_idx++;
      }

      if (mid1 == idx) {
          result += static_cast<double>(val);
      }
      if (mid2 == idx) {
          result += static_cast<double>(val);
          break;
      }
   }
   return result / 2.0;
}

int main()
{
   vector<int> nums1 = { 1, 2 };
   vector<int> nums2 = { 3 };
   cout << findMedianSortedArrays( nums1, nums2 ) << endl;
   return 0;
}