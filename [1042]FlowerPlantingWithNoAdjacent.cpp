/*
 * https://leetcode.com/problems/flower-planting-with-no-adjacent/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) 
{
   vector<vector<int>> adjacent_list(N);
   for (auto p : paths) {
      adjacent_list[p[0] - 1].push_back( p[1] - 1 );
      adjacent_list[p[1] - 1].push_back( p[0] - 1 );
   }
   
   vector<int> flowers(N, 0);
   for (int i = 0; i < N; ++i) {
      vector<bool> used(5, false);
      for (const auto& j : adjacent_list[i]) {
         used[flowers[j]] = true;
      }
      for (int f = 1; f <= 4; ++f) {
         if (!used[f]) flowers[i] = f;
      }
   }
   return flowers;
}

int main()
{
   vector<vector<int>> paths = {
      { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 1 }, { 1, 3 }, { 2, 4 } 
   };
   vector<int> flowers = gardenNoAdj( 4, paths );
   for (const auto& f : flowers) {
      cout << f << " ";
   }
   cout << endl;
   return 0;
}