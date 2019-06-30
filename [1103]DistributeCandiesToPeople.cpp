/*
 * https://leetcode.com/problems/distribute-candies-to-people/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> distributeCandies(int candies, int num_people) 
{
   vector<int> given(num_people, 0);
   int n = 1;
   while (candies > 0) {
      given[(n - 1) % num_people] += candies >= n ? n : candies;
      candies -= n;
      n++;
   }
   return given;
}

int main()
{
   vector<int> given = distributeCandies( 7, 4 );
   for (const auto& i : given) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}