#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t) 
{
   if (s == t) return true;

   map<char, char> dic;
   vector<bool> used(256, false);
   for (int i = 0; i < s.length(); ++i) {
      if (dic.find( s[i] ) == dic.end()) {
          if (used[t[i]]) return false;
          
          dic[s[i]] = t[i];
          used[t[i]] = true;
      }
      else {
          if (dic[s[i]] != t[i])
              return false;
      }
   }
   return true;
}