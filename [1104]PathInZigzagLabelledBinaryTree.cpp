/*
 * https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> pathInZigZagTree(int label) 
{
   int level = 0;
   while ((1 << level) <= label) level++;

   vector<int> visit(level);
   visit[level - 1] = label;

   for (int l = level - 2; l >= 0; --l) {
      label >>= 1;
      label = (1 << (l + 1)) - 1 + (1 << l) - label;
      visit[l] = label;
   }
   return visit;
}

int main()
{
   vector<int> path = pathInZigZagTree( 26 );
   for (const auto& p : path) {
      cout << p << " ";
   }
   cout << endl;
   return 0;
}