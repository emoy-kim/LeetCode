#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
{
   // 0: up, 1: right, 2: down, 3: left
   int direction = 0;

   unordered_set<string> dic;
   for (size_t i = 0; i < obstacles.size(); ++i) {
      dic.insert( to_string( obstacles[i][0] ) + "," + to_string( obstacles[i][1] ) );
   }

   int x = 0, y = 0;
   int max_dist = 0;
   for (size_t i = 0; i < commands.size(); ++i) {
      if (commands[i] == -1) direction = (direction + 1) % 4;
      else if (commands[i] == -2) direction = (direction + 3) % 4;
      else {
          string coord;
          for (int s = 1; s <= commands[i]; ++s) {
              int tx = x, ty = y;
              if (direction == 0) coord = to_string( tx ) + "," + to_string( ++ty );
              else if (direction == 1) coord = to_string( ++tx ) + "," + to_string( ty );
              else if (direction == 2) coord = to_string( tx ) + "," + to_string( --ty );
              else coord = to_string( --tx ) + "," + to_string( ty );
              
              if (dic.find( coord ) != dic.end()) break;
              
              x = tx;
              y = ty;
              const int dist = x * x + y * y;
              max_dist = max( max_dist, dist );
          }
      }
   }
   return max_dist;
}