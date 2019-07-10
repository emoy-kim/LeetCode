/*
 * https://leetcode.com/problems/fizz-buzz/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fizzBuzz(int n) 
{
   vector<string> outputs;
   for (int i = 1; i <= n; ++i) {
      const bool three = (i % 3) == 0;
      const bool five = (i % 5) == 0;
      string num;
      if (!three && !five) num = to_string( i );
      else {
          num += three ? "Fizz" : "";
          num += five ? "Buzz" : "";
      }
      outputs.push_back( num );
   }
   return outputs;
}

int main()
{
   vector<string> outputs = fizzBuzz( 15 );
   for (const auto& i : outputs) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}