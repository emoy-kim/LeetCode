/*
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string smallestSubsequence(string text) 
{
   const int len = text.length();
   vector<int> last_occurrence(26);
   for (int i = 0; i < len; ++i) {
      last_occurrence[text[i] - 'a'] = i;
   }
   
   stack<char> words;
   vector<bool> visit(26, false);
   for (int i = 0; i < len; ++i) {
      const char curr = text[i];
      if (visit[curr - 'a']) continue;

      while (!words.empty() && curr < words.top() && i < last_occurrence[words.top() - 'a']) {
         visit[words.top() - 'a'] = false;
         words.pop();
      }

      words.push( curr );
      visit[curr - 'a'] = true;
   }
   
   string sequence;
   while (!words.empty()) {
      sequence.insert( 0, 1, words.top() );
      words.pop();
   }
   return sequence;
}

int main()
{
   string text = "cdadabcc";
   cout << smallestSubsequence( text ).c_str() << endl;
   return 0;
}