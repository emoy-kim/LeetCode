/*
 * https://leetcode.com/problems/counting-bits/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num) 
{
   vector<int> one_nums(num + 1, 0);
   for (int i = 1; i <= num; ++i) {
      const int turn_off_last_one_bit = i & (i - 1);
      one_nums[i] = one_nums[turn_off_last_one_bit] + 1;
   }
   return one_nums;
}

int main()
{
   vector<int> one_nums = countBits( 25 );
   for (const auto& i : one_nums) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}