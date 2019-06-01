/*
 * https://leetcode.com/problems/height-checker/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int>& heights) 
{
   vector<int> aligned(heights);
   sort( aligned.begin(), aligned.end() );

   int n = 0;
   for (size_t i = 0; i < aligned.size(); ++i) {
      if (heights[i] != aligned[i]) {
         n++;
      }
   }
   return n;
}

int main()
{
   vector<int> heights = { 1,1,4,2,1,3 };
   cout << heightChecker( heights ) << endl;
   return 0;
}