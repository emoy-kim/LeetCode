/*
 * https://leetcode.com/problems/unique-morse-code-words/
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) 
{
   vector<string> code = {
      ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
      ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", 
      ".--", "-..-", "-.--", "--.."
   };
   unordered_set<string> set;
   for (const auto& w : words) {
      string morse;
      for (const auto& c : w) {
          morse += code[c - 'a'];
      }
      set.insert( morse );
   }
   return set.size();
}

int main()
{
   vector<string> words = { "gin", "zen", "gig", "msg" };
   cout << uniqueMorseRepresentations( words ) << endl;
   return 0;
}