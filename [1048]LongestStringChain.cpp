/*
 * https://leetcode.com/problems/longest-string-chain
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int longestStrChain(vector<string>& words) 
{
   sort( words.begin(), words.end(), 
      [](const string& s1, const string& s2)
      {
         return s1.length() < s2.length();
      } 
   );

   unordered_map<string, int> map;
   for (const auto& word : words) {
      map[word] = 1;
   }

   int max_len = 0;
   for (const auto& word : words) {
      const int curr_len = word.length();
      if (curr_len <= 1) continue;

      for (int i = 0; i < curr_len; ++i) {
         const string prev_word = word.substr( 0, i ) + word.substr( i + 1 );
         const auto it = map.find( prev_word );
         if (it != map.end()) {
            const int curr_val = map[word];
            map[word] = max( curr_val, it->second + 1 );
         }
      }

      max_len = max( max_len, map[word] );
   }
   return max_len;
}

int main()
{
   vector<string> words = { "a", "b", "ba", "bca", "bda", "bdca" };
   cout << longestStrChain( words ) << endl;
   return 0;
}