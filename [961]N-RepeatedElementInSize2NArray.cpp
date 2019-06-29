/*
 * https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
 */

#include <iostream>
#include <vector>

using namespace std;

int repeatedNTimes(vector<int>& A) 
{
   vector<int> table(10000, 0);

   int repeated = 0;
   for (const auto& i : A) {
      table[i]++;
      if (table[i] == 2) {
          repeated = i;
          break;
      }
   }
   return repeated;
}

int main()
{
   vector<int> A = { 5,1,5,2,5,3,5,4 };
   cout << repeatedNTimes( A ) << endl;
   return 0;
}