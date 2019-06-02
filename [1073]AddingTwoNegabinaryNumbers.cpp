/*
 * https://leetcode.com/problems/adding-two-negabinary-numbers/
 * 
 * reference: https://en.wikipedia.org/wiki/Negative_base#Addition
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) 
{
   vector<int> added;

   int carry = 0;
   const int l1 = arr1.size();
   const int l2 = arr2.size();
   const int size = max( l1, l2 );
   for (int i = 0; i < size || carry != 0; ++i) {
      int sum = carry;
      if (i < l1) sum += arr1[l1 - i - 1];
      if (i < l2) sum += arr2[l2 - i - 1];

      carry = sum > 1 ? -1 : sum < 0 ? 1 : 0;
      added.insert( added.begin(), sum > 1 ? sum - 2 : sum < 0 ? 1 : sum );
   }
   while (added.size() > 1 && added.front() == 0) added.erase( added.begin() );
   return added;
}

int main()
{
   vector<int> arr1 = { 1, 1, 1, 1, 1 };
   vector<int> arr2 = { 1, 0, 1 };
   vector<int> added = addNegabinary( arr1, arr2 );
   for (const auto& i : added) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}