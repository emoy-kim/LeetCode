/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (30.94%)
 * Total Accepted:    169.5K
 * Total Submissions: 547.7K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
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

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
{
   if (intervals.empty()) return vector<Interval>{newInterval};

   vector<Interval> inserted;
   inserted.emplace_back( 
      min( newInterval.start, newInterval.end ),
      max( newInterval.start, newInterval.end )
   );
   for (const auto& interval : intervals) {
      Interval candidate(
         min( interval.start, interval.end ),
         max( interval.start, interval.end )
      );
      for (auto it = inserted.begin(); it != inserted.end();) {
         if (it->start <= candidate.end && candidate.start <= it->end) {
            candidate.start = min( it->start, candidate.start );
            candidate.end = max( it->end, candidate.end );
            it = inserted.erase( it );
         }
         else ++it;
      }
      inserted.push_back( candidate );
   }
   sort( 
      inserted.begin(), inserted.end(), 
      [](const Interval& a, const Interval& b)
         {
            return a.start < b.start;
         }
   );
   return inserted;
}

int main()
{
   vector<Interval> intervals = {
      Interval(1, 5),
      Interval(3, 5),
      Interval(6, 7),
      Interval(8, 10),
      Interval(12, 16),
   };
   const vector<Interval> inserted = insert( intervals, Interval{ 6, 8 } );
   for (const auto& interval : inserted) {
      cout << "[" << interval.start << ", " << interval.end << "] ";
   }
   cout << endl;
   return 0;
}