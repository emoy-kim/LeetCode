/*
 * https://leetcode.com/problems/robot-return-to-origin/
 */

#include <iostream>
#include <string>

using namespace std;

bool judgeCircle(string moves) 
{
   int x = 0, y = 0;
   for (const auto& c : moves) {
      if (c == 'L') x--;
      else if (c == 'R') x++;
      else if (c == 'U') y++;
      else if (c == 'D') y--;
   }
   return x == 0 && y == 0;
}

int main()
{
   cout << judgeCircle( "UD" ) << endl;
   return 0;
}