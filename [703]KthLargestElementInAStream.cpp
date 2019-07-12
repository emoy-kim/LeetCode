/*
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class KthLargest 
{
    multiset<int> elems;
    int k_th;
    
public:
    KthLargest(int k, vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        
        const int size = nums.size();
        const int start = max( size - k, 0 );
        for (int i = start; i < size; ++i) {
            elems.insert( nums[i]);
        }
        k_th = k;
    }
    
    int add(int val) {
        if (elems.size() < k_th) elems.insert( val );
        else if (val > *elems.begin()) {
            elems.insert( val );
            elems.erase( elems.begin() );
        }
        return *elems.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
   vector<int> nums = { 4, 5, 8, 2 };
   auto* obj = new KthLargest(3, nums);
   cout << obj->add( 3 ) << endl;
   cout << obj->add( 5 ) << endl;
   cout << obj->add( 10 ) << endl;
   cout << obj->add( 9 ) << endl;
   cout << obj->add( 4 ) << endl;
   return 0;
}