/*
 * https://leetcode.com/problems/grumpy-bookstore-owner/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) 
{
   int total_num = 0;
   int total_not_satisfied_num = 0;
   const int minutes = customers.size();
   vector<int> not_satisfied(minutes, 0);
   for (int i = 0; i < minutes; ++i) {
      if (grumpy[i]) {
         not_satisfied[i] = customers[i];
         total_not_satisfied_num += customers[i];
      }
      total_num += customers[i];
   }

   int curr_sum = 0;
   for (int i = 0; i < X; ++i) {
      curr_sum += not_satisfied[i];
   }

   int max_not_satisfied_num = curr_sum;
   for (int i = 1; i <= minutes - X; ++i) {
      curr_sum = curr_sum - not_satisfied[i - 1] + not_satisfied[i + X - 1];
      max_not_satisfied_num = max( max_not_satisfied_num, curr_sum );
   }

   return total_num - total_not_satisfied_num + max_not_satisfied_num;
}

int main()
{
   vector<int> customers = { 1,0,1,2,1,1,7,5 };
   vector<int> grumpy = { 0,1,0,1,0,1,0,1 };
   const int X = 3;
   cout << maxSatisfied( customers, grumpy, X ) << endl;
   return 0;
}