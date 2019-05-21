/*
 * https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 */

#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) 
{
   for (const auto c : letters) {
      if (target < c) return c;
   }

   for (const auto c : letters) {
      if (target != c) return c;
   }

   return letters[0];
}

int main()
{
   vector<char> letters = { 'c', 'c', 'j' };
   const char target = 'j';

   cout << nextGreatestLetter( letters, target ) << endl;
   return 0;
}