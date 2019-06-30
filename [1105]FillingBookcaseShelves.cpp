/*
 * https://leetcode.com/problems/filling-bookcase-shelves/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minHeightShelves(vector<vector<int>>& books, int shelf_width) 
{
   const int size = books.size();
   vector<int> table(size + 1, 0);
   for (int i = 1; i <= size; ++i) {
      int width = books[i - 1][0];
      int height = books[i - 1][1];
      table[i] = table[i - 1] + height;
      
      for (int j = i - 1; j > 0 && width + books[j - 1][0] <= shelf_width; --j) {
         height = max( height, books[j - 1][1] );
         width += books[j - 1][0];
         table[i] = min( table[i], table[j - 1] + height );
      }
   }
   return table[books.size()];
}

int main()
{
   vector<vector<int>> books = { { 1,1 }, { 2,3 }, { 2,3 }, { 1,1 }, { 1,1 }, { 1,1 }, { 1,2 } };
   cout << minHeightShelves( books, 4 ) << endl;
   return 0;
}