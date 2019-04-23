/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (37.82%)
 * Total Accepted:    172.6K
 * Total Submissions: 456.2K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Trie {
   set<string> table;

public:
   /** Initialize your data structure here. */
   Trie() {
     
   }

   /** Inserts a word into the trie. */
   void insert(string word) {
      table.insert( word );
   }

   /** Returns if the word is in the trie. */
   bool search(string word) {
     return table.find( word ) != table.end();
   }

   /** Returns if there is any word in the trie that starts with the given prefix. */
   bool startsWith(string prefix) {
      const size_t len = prefix.length();
      for (const auto& word : table) {
         if (len <= word.length() && word.substr(0, len ) == prefix) {
            return true;
         }
      }
      return false;
   }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
   Trie* trie = new Trie();

   trie->insert("apple");
   cout << trie->search("apple") << endl;   // returns true
   cout << trie->search("app") << endl;     // returns false
   cout << trie->startsWith("app") << endl; // returns true
   trie->insert("app");   
   cout << trie->search("app") << endl;     // returns true
   return 0;
}