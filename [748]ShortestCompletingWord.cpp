/*
 * https://leetcode.com/problems/shortest-completing-word/
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string shortestCompletingWord(string licensePlate, vector<string>& words) 
{
   map<char, int> dictionary;
   for (const auto& c : licensePlate) {
      char word = 0;
      if ('a' <= c && c <= 'z') word = c;
      else if ('A' <= c && c <= 'Z') word = c - 'A' + 'a';

      if (word != 0) {
         const auto it = dictionary.find( word );
         if (it != dictionary.end()) it->second++;
         else dictionary[word] = 1;
      }
   }

   int match_index = -1;
   size_t match_length = 10000;
   for (size_t i = 0; i < words.size(); ++i) {
      vector<int> letters(26, 0);
      for (const auto& c : words[i]) {
         letters[c - 'a']++;
      }

      bool match = true;
      for (const auto& it : dictionary) {
         if (it.second > letters[it.first - 'a']) {
            match = false;
            break;
         }
      }
      if (match && words[i].length() < match_length) {
         match_length = words[i].length();
         match_index = i;
      }
   }

   return words[match_index];
}

int main()
{
   string licensePlate = "GrC8950";
   vector<string> words = { "measure","other","every","base","according","level","meeting","none","marriage","rest" };
   cout << shortestCompletingWord( licensePlate, words ).c_str() << endl;
   return 0;
}