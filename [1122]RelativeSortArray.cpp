/*
 * https://leetcode.com/problems/relative-sort-array/
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
{
   unordered_map<int, int> table;
   for (const auto& i : arr1) {
      const auto it = table.find( i );
      if (it != table.end()) it->second++;
      else table[i] = 1;
   }

   vector<int> sorted;
   for (const auto& i : arr2) {
      const auto it = table.find( i );
      for (int j = 0; j < it->second; ++j) {
          sorted.push_back( i );
      }
      it->second = 0;
   }

   int non_exist_num = 0;
   for (const auto& it : table) {
      if (it.second != 0) {
         for (int j = 0; j < it.second; ++j) {
            sorted.push_back( it.first );
            non_exist_num++;
         }
      }
   }
   sort( sorted.end() - non_exist_num, sorted.end() );
   return sorted;
}

int main()
{
   vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
   vector<int> arr2 = { 2,1,4,3,9,6 };
   vector<int> sorted = relativeSortArray( arr1, arr2 );
   for (const auto& i : sorted) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}