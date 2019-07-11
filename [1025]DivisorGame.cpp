/*
 * https://leetcode.com/problems/divisor-game/
*/

#include <iostream>

using namespace std;

bool divisorGame(int N) 
{
   return (N & 1) == 0;
}

int main()
{
   cout << divisorGame( 2 ) << endl;
   return 0;
}