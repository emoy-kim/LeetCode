/*
 * https://leetcode.com/problems/sum-of-two-integers/
 */

#include <iostream>

using namespace std;

int getSum(int a, int b) 
{
   return b == 0 ? a : getSum( a ^ b, static_cast<unsigned int>(a & b) << 1 );
}

int main()
{
   cout << getSum( 1, -2 ) << endl;
   return 0;
}