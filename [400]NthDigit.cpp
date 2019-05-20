#include <iostream>
#include <string>

using namespace std;

int findNthDigit(int n) 
{
   if (n < 10) return n;

   int digit_num = 1;
   int64_t num = 9;
   int64_t x = n - num;

   while (x > 0) {
      digit_num++;
      if (digit_num == 10) {
          x -= num;
          break;
      }
      num = static_cast<int64_t>(pow( 10, digit_num - 1 )) * 9 * digit_num;
      x -= num;
   }
   x += num;
   x--;
   n = x;

   int q = n / digit_num;
   int r = n % digit_num;
   string str = to_string( static_cast<int>(pow( 10, digit_num - 1 )) + q );
   return str[r] - '0';
}