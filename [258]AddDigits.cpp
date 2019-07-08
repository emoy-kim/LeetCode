/*
 * https://leetcode.com/problems/add-digits/
 */

#include <iostream>

using namespace std;

int addDigits(int num) 
{
   if (num == 0) return 0;
   const int sum = num % 9;
   return sum == 0 ? 9 : sum;
}

int main()
{
   cout << addDigits( 832091 ) << endl;
   return 0;
}