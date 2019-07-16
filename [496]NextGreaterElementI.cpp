/*
 * https://leetcode.com/problems/next-greater-element-i/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
   const int size = nums2.size();
   unordered_map<int, int> table;
   for (int i = 0; i < size; ++i) {
      table[nums2[i]] = i;
   }

   vector<int> next_greater;
   for (const auto& n : nums1) {
      const auto it = table.find( n );
      int next = -1;
      for (int i = it->second + 1; i < size; ++i) {
          if (nums2[i] > it->first) {
              next = nums2[i];
              break;
          }
      }
      next_greater.push_back( next );
   }
   return next_greater;
}

int main()
{
   vector<int> nums1 = { 4, 1, 2 };
   vector<int> nums2 = { 1, 3, 4, 2 };
   vector<int> next_greater = nextGreaterElement( nums1, nums2 );
   for (const auto& n : next_greater) {
      cout << n << " ";
   }
   cout << endl;
   return 0;
}