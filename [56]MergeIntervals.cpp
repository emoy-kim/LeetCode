/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (35.17%)
 * Total Accepted:    323.6K
 * Total Submissions: 919.6K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval 
{
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals) 
{
   if (intervals.empty()) return vector<Interval>();

   vector<Interval> merged;
   merged.emplace_back( 
      min( intervals[0].start, intervals[0].end ),
      max( intervals[0].start, intervals[0].end )
   );
   for (size_t i = 1; i < intervals.size(); ++i) {
      Interval candidate(
         min( intervals[i].start, intervals[i].end ),
         max( intervals[i].start, intervals[i].end )
      );
      for (auto it = merged.begin(); it != merged.end();) {
         if (it->start <= candidate.end && candidate.start <= it->end) {
            candidate.start = min( it->start, candidate.start );
            candidate.end = max( it->end, candidate.end );
            it = merged.erase( it );
         }
         else ++it;
      }
      merged.push_back( candidate );
   }
   return merged;
}

int main()
{
   vector<Interval> intervals = {
      Interval(1, 4),
      Interval(4, 5),
      Interval(8, 10),
      Interval(15, 18),
   };
   const vector<Interval> merged = merge( intervals );
   for (const auto& interval : merged) {
      cout << "[" << interval.start << ", " << interval.end << "] ";
   }
   cout << endl;
   return 0;
}