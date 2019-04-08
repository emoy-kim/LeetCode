/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (24.56%)
 * Total Accepted:    275.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 ); // capacity
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LRUCache {
   int size;
   deque<int> key_stack;
   unordered_map<int, int> mapper;

public:
   LRUCache(int capacity) 
   {
      size = capacity;
   }
    
   int get(int key) 
   {
      const auto it = find( key_stack.begin(), key_stack.end(), key );
      if (it != key_stack.end()) {
         key_stack.erase( it );
         key_stack.push_back( key );
         return mapper[key];
      }
      return -1;
   }
    
   void put(int key, int value) 
   {
      const auto it = find( key_stack.begin(), key_stack.end(), key );
      if (it == key_stack.end()) {
         if (static_cast<int>(key_stack.size()) == size) {
            key_stack.pop_front();
         }
         key_stack.push_back( key );
      }
      else {
         key_stack.erase( it );
         key_stack.push_back( key );
      }
      mapper[key] = value;
   }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
   const int capacity = 2;
   auto* cache = new LRUCache(capacity);
   cache->put( 1, 1 );
   cache->put( 2, 2 );
   cout << cache->get( 1) << endl;           // returns 1
   cache->put( 3, 3 );  // evicts key 2
   cout << cache->get( 2) << endl;           // returns -1 (not found)
   cache->put( 4, 4 );  // evicts key 1
   cout << cache->get( 1) << endl;           // returns -1 (not found)
   cout << cache->get( 3) << endl;           // returns 3
   cout << cache->get( 4) << endl;           // returns 4
   return 0;
}