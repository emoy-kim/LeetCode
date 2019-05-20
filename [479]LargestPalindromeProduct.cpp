#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

uint64_t getPalindrome(int val)
{
  string s = to_string( val );
  string r = s;
  reverse( r.begin(), r.end() );
  s += r;
  return stoll( s );
}

int largestPalindrome(int n) 
{
   if (n == 1) return 9;

   const int max_val = pow( 10, n ) - 1;
   const int min_val = pow( 10, n - 1 );
   for (int bigger = max_val; bigger >= min_val; --bigger) {
      const uint64_t palindrome = getPalindrome( bigger );
      uint64_t p = max_val;
      while (p * p >= palindrome) {
          if (palindrome % p == 0 && palindrome / p >= min_val)
              return palindrome % 1337;
          p--;
      }
   }
}