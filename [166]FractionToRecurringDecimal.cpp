/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (19.28%)
 * Total Accepted:    84.7K
 * Total Submissions: 439.4K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * Example 1:
 * 
 * 
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * Example 3:
 * 
 * 
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string fractionToDecimal(int numerator, int denominator) 
{
   if (numerator == 0) return "0";

   bool sign = true;
   int64_t n = numerator, d = denominator;
   if (n < 0) {
      sign = !sign;
      n = -n;
   }
   if (d < 0) {
      sign = !sign;
      d = -d;
   }

   string result;
   if (!sign) result += "-";

   int64_t q = n / d;
   int64_t r = n % d;
   result += to_string( q );
   if (r != 0) result += ".";

   vector<int64_t> r_history = { r };
   while (r != 0) {
      n = r * 10;
      q = n / d;
      r = n % d;

      result += to_string( q );
      
      auto it = find( r_history.begin(), r_history.end(), r );
      if (it != r_history.end()) {
         const int repeat_size = distance( it, r_history.end() );
         result.insert( result.end() - repeat_size, '(' );
         result += ")";
         break;
      }
      r_history.push_back( r );
   }
   return result;
}

int main()
{
   cout << fractionToDecimal( 1, 1 ) << endl;
   return 0;
}