/*
 * https://leetcode.com/problems/video-stitching/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int videoStitching(vector<vector<int>>& clips, int T) 
{
   sort( clips.begin(), clips.end() );

   size_t i = 0;
   int clip_num = 0, end = 0;
   while (end < T) {
      const int pos = end;
      while (i < clips.size() && clips[i][0] <= pos) {
         end = max( end, clips[i][1] );
         i++;
      }
      if (pos == end) return -1;
      clip_num++;
   }
   return clip_num;
}

int main()
{
   vector<vector<int>> clips = { 
      { 0,2 }, { 4,6 }, { 8,11 }, { 1,9 }, { 1,5 }, { 5,9 }
   };
   cout << videoStitching( clips, 5 ) << endl;
   return 0;
}