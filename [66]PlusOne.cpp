#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
   vector<int> result;
   int carry = 1;
   for (int i = digits.size() - 1; i >= 0; --i) {
      int val = digits[i] + carry;
      if (val >= 10) {
          carry = 1;
          val -= 10;
      }
      else carry = 0;
      result.insert( result.begin(), val );
   }
   if (carry == 1) {
      result.insert( result.begin(), 1 );
   }

   return result;
}