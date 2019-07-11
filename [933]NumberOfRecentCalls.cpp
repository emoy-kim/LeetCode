/*
 * https://leetcode.com/problems/number-of-recent-calls/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RecentCounter 
{
    vector<int> pings;
    
public:
    RecentCounter() {}
    
    int ping(int t) {
        pings.push_back( t );
        return count_if( pings.begin(), pings.end(), 
            [&](int i) { return t - 3000 <= i && i <= t; } 
        );
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{
   auto* obj = new RecentCounter();
   cout << obj->ping( 1 ) << endl;
   cout << obj->ping( 100 ) << endl;
   cout << obj->ping( 3001 ) << endl;
   cout << obj->ping( 3002 ) << endl;
   return 0;
}