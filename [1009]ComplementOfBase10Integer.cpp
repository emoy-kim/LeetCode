/*
 * https://leetcode.com/problems/complement-of-base-10-integer/
 */

#include <iostream>
#include <vector>

using namespace std;

int bitwiseComplement(int N) 
{
   if (N == 0) return 1;

   int n = 1;
   vector<int> table(31);
   for (int i = 1; i <= 30; ++i) {
      n *= 2;
      table.push_back( n - 1 );
   }
   table.push_back( INT_MAX );

   for (size_t i = 1; i < table.size(); ++i) {
      if (table[i - 1] < N && N <= table[i]) {
         return table[i] - N;
      }
   }
   return 0;
}

int main()
{
   cout << bitwiseComplement( 139327 ) << endl;
   return 0;
}