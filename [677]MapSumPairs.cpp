/*
 * https://leetcode.com/problems/map-sum-pairs/
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class MapSum {
    unordered_map<string, int> map;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        map[key] = val;
    }
    
    int sum(string prefix) {
        int s = 0;
        for (const auto& n : map) {
            if (n.first.substr( 0, prefix.length() ) == prefix) {
                s += n.second;
            }
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */