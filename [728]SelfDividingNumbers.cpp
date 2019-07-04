/*
 * https://leetcode.com/problems/self-dividing-numbers/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> selfDividingNumbers(int left, int right) 
{
   vector<int> divided;
   for (int n = left; n <= right; ++n) {
      bool self_divided = true;
      string num = to_string( n );
      for (auto c : num) {
          const int i = c - '0';
          if (i == 0 || (n % i) != 0) {
              self_divided = false;
              break;
          }
      }
      if (self_divided) {
          divided.push_back( n );
      }
   }
   return divided;
}

int main()
{
   vector<int> divided = selfDividingNumbers( 1, 22 );
   for (const auto& i : divided) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}