/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (42.42%)
 * Total Accepted:    270.9K
 * Total Submissions: 638.6K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int calculatePartialVolume(int& start, const vector<int>& height)
{
   int h = height[start];
   const int size = height.size();
   while (start < size) {
      int volume = 0;
      int second_max = -1;
      int second_max_index = -1;
      bool maxima_exists = false;
      for (size_t i = start + 1; i < height.size(); ++i) {
         if (height[i] >= h) {
            start = i;
            return volume;
         }
         
         if (height[i - 1] < height[i]) {
            maxima_exists = true;
         }

         if (height[i] > second_max) {
            second_max = height[i];
            second_max_index = i;
         }

         volume += h - height[i];
      }
      if (!maxima_exists) break;
      h = height[second_max_index];
   }
   return -1;
}

int trap(vector<int>& height) 
{
   int start = 0;
   const int size = height.size();
   for (int i = 0; i < size; ++i) {
      if (height[i] > 0) {
         start = i;
         break;
      }
   }
   
   int volume = 0;
   while (start < size) {
      const int partial = calculatePartialVolume( start, height );
      if (partial < 0) {
         start++;
         continue;
      }
      volume += partial;
   }
   return volume;
}

int main()
{
   vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
   cout << trap( height ) << endl;
   return 0;
}