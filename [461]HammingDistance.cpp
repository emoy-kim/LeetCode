/*
 * https://leetcode.com/problems/hamming-distance/
 */

#include <iostream>

using namespace std;

int hammingDistance(int x, int y) 
{
   int distance = 0;
   while (x != 0 || y != 0) {
      distance += (x & 1) ^ (y & 1);
      x >>= 1;
      y >>= 1;
   }
   return distance;
}

int main()
{
   cout << hammingDistance( 5, 7 ) << endl;
   return 0;
}