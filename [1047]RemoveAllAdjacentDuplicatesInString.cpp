/*
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 */

#include <iostream>
#include <string>

using namespace std;

string removeDuplicates(string S) 
{
   string result = S;
   while (true) {
      string removed;
      const int length = result.length();
      for (int i = 0; i < length; ++i) {
         if (i == length - 1 || result[i] != result[i + 1]) {
            removed.push_back( result[i] );
         }
         else i++;
      }
      if (result == removed) break;
      result = removed;
   }
   return result;
}

int main()
{
   string S = "aabaa";
   cout << removeDuplicates( S ) << endl;
   return 0;
}