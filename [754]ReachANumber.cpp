#include <iostream>

using namespace std;

int reachNumber(int target) 
{
   if (target == 0) return 0;

   target = abs( target );

   const int is_odd = target & 1;
   int level = static_cast<int>(ceil( (sqrt( 8.0 * target + 1.0 ) - 1.0) * 0.5 ));
   int max_val;
   if (level & 1) {
      max_val = (level + 1) / 2;
      max_val *= level;
   }
   else { 
      max_val = level / 2;
      max_val *= level + 1;
   }

   while ((max_val & 1) != is_odd) {
      level++;
      max_val += level;
   }
   return level;
}