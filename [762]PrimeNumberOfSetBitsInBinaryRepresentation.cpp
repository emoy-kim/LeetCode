/*
 * https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
 */

#include <iostream>
#include <map>

using namespace std;

int countOneBits(int n) 
{ 
   int count = 0; 
   while (n) { 
      n &= n - 1; 
      count++; 
   } 
   return count; 
}

bool isPrime(int n)
{
   if (n <= 1) return false;

   bool is_prime = true;
   for (int i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
         is_prime = false;
         break;
      }
   }
   return is_prime;
}

int countPrimeSetBits(int L, int R) 
{
   map<int, bool> prime_table;
   
   int count = 0;
   for (int i = L; i <= R; ++i) {
      const int one_bits = countOneBits( i );
      const auto it = prime_table.find( one_bits );
      if (it == prime_table.end()) {
         prime_table[one_bits] = isPrime( one_bits );
         if (prime_table[one_bits]) count++;
      }
      else if (it->second) count++;
   }
   return count;
}

int main()
{
   const int L = 10;
   const int R = 15;
   cout << countPrimeSetBits( L, R ) << endl;
   return 0;
}