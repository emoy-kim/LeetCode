/*
 * https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canThreePartsEqualSum(vector<int>& A) 
{
   const int total_sum = accumulate( A.begin(), A.end(), 0 );
   if (total_sum % 3 != 0) return false;

   const int partition = total_sum / 3;

   int n = 0, sum = 0;
   for (const auto& i : A) {
      sum += i;
      if (sum == partition) {
         n++;
         sum = 0;
      }
   }
   return n == 3;
}

int main()
{
   vector<int> A = { 3,3,6,5,-2,2,5,1,-9,4 };
   cout << canThreePartsEqualSum( A ) << endl;
   return 0;
}