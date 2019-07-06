/*
 * https://leetcode.com/problems/di-string-match/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> diStringMatch(string S) 
{
   vector<int> nums;
   int inc = 0, dec = S.length();
   for (size_t i = 0; i <= S.length(); ++i) {
      if (i == S.length() || S[i] == 'I') {
          nums.push_back( inc );
          inc++;
      }
      else {
          nums.push_back( dec );
          dec--;
      }
   }
   return nums;
}

int main()
{
   vector<int> nums = diStringMatch( "DIDI" );
   for (const auto& n : nums) {
      cout << n << " ";
   }
   cout << endl;
   return 0;
}