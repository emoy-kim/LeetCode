#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool buddyStrings(string A, string B) 
{
   if (A.empty() || B.empty()) return false;
   if (A.length() != B.length()) return false;
   if (A.length() == 1) return false;

   vector<int> A_visited(26, 0);
   vector<int> B_visited(26, 0);
   string A_reduced, B_reduced;
   for (int i = 0; i < A.length(); ++i) {
      if (A[i] == B[i]) {
          A_visited[A[i] - 'a']++;
          B_visited[B[i] - 'a']++;
          continue;   
      }
      
      A_reduced += A[i];
      B_reduced += B[i];
   }

   // case1: A == B -> check duplication
   if (A_reduced.empty()) {
      for (int i = 0; i < 26; ++i) {
          if (A_visited[i] >= 2) return true;
      }
      return false;
   }
   // case2: A's size is not 2 -> cannot swap
   if (A_reduced.length() != 2) return false;

   // case3: A's size is 2 -> check using swap
   return A_reduced[0] == B_reduced[1] && A_reduced[1] == B_reduced[0];
}