/*
 * https://leetcode.com/problems/binary-prefix-divisible-by-5/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> prefixesDivBy5(vector<int>& A) 
{
   vector<bool> prefixes;

   int n = 0;
   for (const auto& i : A) {
      n = (n * 2 + i) % 5;
      prefixes.push_back( n == 0 );
   }
   return prefixes;
}

int main()
{
   vector<int> A = { 1, 1, 1, 0, 1 };
   vector<bool> prefixes = prefixesDivBy5( A );
   for (const auto& i : prefixes) {
      if (i) cout << "true ";
      else cout << "false ";
   }
   cout << endl;
   return 0;
}