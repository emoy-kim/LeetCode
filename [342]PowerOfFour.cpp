/*
 * https://leetcode.com/problems/power-of-four/
 */

#include <iostream>

using namespace std;

bool isPowerOfFour(int num)
{
   return num > 0 && ((num & (num - 1)) == 0) && !(num & 0xAAAAAAAA);
}

int main()
{
   cout << isPowerOfFour( 16 ) << endl;
   return 0;
}