/*
 * https://leetcode.com/problems/jewels-and-stones/
 */

#include <iostream>
#include <string>

using namespace std;

int numJewelsInStones(string J, string S) 
{
   int count = 0;
   for (const auto& j : J) {
      for (const auto& s : S) {
          if (s == j) count++;
      }
   }
   return count;
}

int main()
{
   cout << numJewelsInStones( "aA", "aAAbbbb" ) << endl;
   return 0;
}