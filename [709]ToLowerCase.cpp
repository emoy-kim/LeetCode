/*
 * https://leetcode.com/problems/to-lower-case/
 */

#include <iostream>
#include <string>

using namespace std;

string toLowerCase(string str) 
{
   const int to_lower = 'a' - 'A';
   for (auto& c : str) {
      if ('A' <= c && c <= 'Z') c += to_lower;
   }
   return str;
}

int main()
{
   cout << toLowerCase( "LOVELY" ).c_str() << endl;
   return 0;
}