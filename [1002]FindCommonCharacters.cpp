/*
 * https://leetcode.com/problems/find-common-characters/
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> commonChars(vector<string>& A) 
{
   vector<vector<int>> table(A.size(), vector<int>(26, 0));
   for (size_t i = 0; i < A.size(); ++i) {
      for (const auto& c : A[i]) {
         table[i][c - 'a']++;
      }
   }

   vector<string> common;
   for (int c = 0; c < 26; ++c) {
      if (table[0][c] == 0) continue;

      int min_num = table[0][c];
      for (size_t i = 1; i < table.size(); ++i) {
         min_num = min( min_num, table[i][c] );
      }
      for (int n = 0; n < min_num; ++n) {
         common.emplace_back( 1, 'a' + c );
      }
   }
   return common;
}

int main()
{
   vector<string> A =  { "bella","label","roller" };
   vector<string> common = commonChars( A );
   for (const auto& i : common) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}