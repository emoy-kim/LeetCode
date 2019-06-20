/*
 * https://leetcode.com/problems/number-complement/
 */

#include <iostream>

using namespace std;

int findComplement(int num) 
{
   int64_t min_power = 1;
   while (num > min_power - 1) {
      min_power *= 2;
   }
   min_power--;
   return static_cast<int>(min_power) - num;
}

int main()
{
   cout << findComplement( 7 ) << endl;

   return 0;
}