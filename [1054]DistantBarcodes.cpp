/*
 * https://leetcode.com/problems/distant-barcodes/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rearrangeBarcodes(vector<int>& barcodes) 
{
   sort( barcodes.begin(), barcodes.end() );
   
   vector<pair<int, int>> frequencies;
   frequencies.emplace_back( barcodes[0], 1 );
   for (size_t i = 1; i < barcodes.size(); ++i) {
      if (barcodes[i] != barcodes[i - 1]) {
         frequencies.emplace_back( barcodes[i], 1 );
      }
      else frequencies.back().second++;
   }

   sort( frequencies.begin(), frequencies.end(), 
      [](const pair<int, int>& f1, const pair<int, int>& f2)
         {
            return f1.second > f2.second;
         }
   );

   size_t position = 0;
   vector<int> rearranged(barcodes.size(), 0);
   for (const auto& f : frequencies) {
      for (int i = 0; i < f.second; ++i) {
         if (position >= rearranged.size()) position  = 1;

         rearranged[position] = f.first;
         position += 2;
      }
   }
   return rearranged;
}

int main()
{
   vector<int> barcodes = { 1,1,1,2,2,2 };
   vector<int> rearranged = rearrangeBarcodes( barcodes );
   for (const auto& i : rearranged) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}