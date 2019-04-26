/*
 * Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. 
 * Find and return the shortest palindrome you can find by performing this transformation.
 *
 *
 * Example 1:
 * 
 * Input: "aacecaaa"
 * Output: "aaacecaaa"
 * 
 * 
 * Example 2:
 * 
 * Input: "abcd"
 * Output: "dcbabcd"
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Time Limit Exceeded
bool isPalindrome(const string& s)
{
   int end = s.length() - 1;
   const int half = s.length() / 2;
   for (int i = 0; i <= half; ++i) {
      if (s[i] != s[end]) return false;
      end--;
   }
   return true;
}

string shortestPalindrome(string s) 
{
   if (s.length() <= 1) return s;

   string palindrome = s;
   int end = s.length() - 1;
   while (!isPalindrome( palindrome )) {
      palindrome = s.substr( end );
      reverse( palindrome.begin(), palindrome.end() );
      palindrome += s;
      end--;
   }
   return palindrome;
}
*/

string shortestPalindrome(string s) 
{
   if (s.length() <= 1) return s;

   const int size = s.length();
   const int half = size / 2;
   int max_len = 1;
   for (int i = 0; i <= half;) {
      int start = i, end = i;
      while (end < size - 1 && s[end] == s[end + 1]) end++;

      i = end + 1;
      while (start > 0 && end < size - 1 && s[start - 1] == s[end + 1]) {
         start--;
         end++;
      }

      if (start == 0 && end - start + 1 > max_len) {
         max_len = end - start + 1;
      }
   }

   string palindrome = s.substr( max_len );
   reverse( palindrome.begin(), palindrome.end() );
   palindrome += s;
   return palindrome;
}

int main()
{
   const string str = "aba";
   cout << shortestPalindrome( str ) << endl;
   return 0;
}