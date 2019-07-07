/*
 * https://leetcode.com/problems/corporate-flight-bookings/
 */

#include <iostream>
#include <vector>

using namespace std;

#if 0 // time limit exceeded
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
{
   vector<int> booked_num(n, 0);
   for (const auto& list : bookings) {
      const int b = list[2];
      for (size_t i = list[0] - 1; i < list[1]; ++i) {
          booked_num[i] += b;
      }
   }
   return booked_num;
}
#endif

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
{
   vector<int> booked_num(n, 0);
   for (const auto& list : bookings) {
      booked_num[list[0] - 1] += list[2];
      if (list[1] < n) booked_num[list[1]] -= list[2];
   }
   for (int i = 1; i < n; ++i) {
      booked_num[i] += booked_num[i - 1];
   }
   return booked_num;
}

int main()
{
   vector<vector<int>> bookings = { { 1, 2, 10 }, { 2, 3, 20 }, { 2, 5, 25 } };
   vector<int> booked = corpFlightBookings( bookings, 5 );
   for (const auto& i : booked) {
      cout << i << " ";
   }
   cout << endl;
   return 0;
}