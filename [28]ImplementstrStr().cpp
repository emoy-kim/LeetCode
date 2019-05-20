#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) 
{
   if (needle.empty()) return 0;

   for (int i = 0; i < haystack.length(); ++i) {
      if (i + needle.length() > haystack.length()) return -1;

      bool found;
      for (int j = 0; j < needle.length(); ++j) {
          if (haystack[i + j] != needle[j]) {
              found = false;
              break;
          }
          found = true;
      }
      if (found) return i;
   }
   return -1;
}