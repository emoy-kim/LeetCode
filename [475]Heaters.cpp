#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) 
{
   if (houses.empty()) return 0;

   sort( houses.begin(), houses.end() );
   sort( heaters.begin(), heaters.end() );

   int radius = 0;
   int start = 0;
   for (size_t i = 0; i < houses.size(); ++i) {
      int min_dist = 1E+9;
      for (size_t j = start; j < heaters.size(); ++j) {
          const int dist = abs( houses[i] - heaters[j] );
          if (dist < min_dist) {
              min_dist = dist;
              start = j;
          }
      }
      radius = max( min_dist, radius );
   }
   return radius;
}