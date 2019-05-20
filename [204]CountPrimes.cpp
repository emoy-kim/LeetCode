#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) 
{
   vector<bool> primes(n, true);
   primes[0] = primes[1] = false;

   for (int i = 2; i * i < n; ++i) {
      if (!primes[i]) continue;
      for (int j = i * i; j < n; j += i) {
          primes[j] = false;
      }
   }

   int num = 0;
   for (int i = 2; i < n; ++i) {
      if (primes[i]) num++;
   }
   return num;
}