#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1;
        int last = n;
        int mid = first + (last - first) / 2;
        
        while (first <= last) {
            bool mid_test = isBadVersion( mid );
            
            if (mid_test) {
                if (first == mid) return mid;
                last = mid;
            }
            else {
                if (first == mid) return mid + 1;
                first = mid;
            }
                
            mid = first + (last - first) / 2;
        }
    }
};