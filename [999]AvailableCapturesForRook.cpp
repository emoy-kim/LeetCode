/*
 * https://leetcode.com/problems/available-captures-for-rook/
 */

#include <iostream>
#include <vector>

using namespace std;

void findR(int& x, int& y, vector<vector<char>>& board)
{
   for (int j = 0; j < 8; ++j) {
      for (int i = 0; i < 8; ++i) {
         if (board[j][i] == 'R') {
            x = i;
            y = j;
            return;
         }
      }
   }
}

int numRookCaptures(vector<vector<char>>& board) 
{
   int x = 0, y = 0;
   findR( x, y, board );

   int captures = 0;
   for (int j = y - 1; j >= 0; --j) {
      if (board[j][x] == 'p') {
         captures++;
         break;
      }
      if (board[j][x] == 'B') break;
   }

   for (int j = y + 1; j < 8; ++j) {
      if (board[j][x] == 'p') {
         captures++;
         break;
      }
      if (board[j][x] == 'B') break;
   }

   for (int i = x - 1; i >= 0; --i) {
      if (board[y][i] == 'p') {
         captures++;
         break;
      }
      if (board[y][i] == 'B') break;
   }

   for (int i = x + 1; i < 8; ++i) {
      if (board[y][i] == 'p') {
         captures++;
         break;
      }
      if (board[y][i] == 'B') break;
   }

   return captures;
}

int main()
{
   vector<vector<char>> board = {
      {'.', '.', '.', '.', '.', '.', '.', '.' },
      {'.', '.', '.', 'p', '.', '.', '.', '.' },
      {'.', '.', '.', 'R', '.', '.', '.', 'p' },
      {'.', '.', '.', '.', '.', '.', '.', '.' },
      {'.', '.', '.', '.', '.', '.', '.', '.' },
      {'.', '.', '.', 'p', '.', '.', '.', '.' },
      {'.', '.', '.', '.', '.', '.', '.', '.' },
      {'.', '.', '.', '.', '.', '.', '.', '.' }
   };
   cout << numRookCaptures( board ) << endl;
   return 0;
}