/*
 * https://leetcode.com/problems/fibonacci-number/
 */

#include <iostream>
#include <vector>

using namespace std;

int f(int N, vector<int>& fibs)
{
   if (fibs[N] >= 0) return fibs[N];
   fibs[N] = f( N - 1, fibs ) + f( N - 2, fibs );
   return fibs[N];
}

int fib(int N) 
{
   vector<int> fibs(31, -1);
   fibs[0] = 0; fibs[1] = 1;
   return f( N, fibs );
}

int main()
{
   cout << fib( 15 ) << endl;
   return 0;
}