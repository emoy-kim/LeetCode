/*
 * https://leetcode.com/problems/battleships-in-a-board/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countBattleships(vector<vector<char>>& board) 
{
   if (board.empty() || board[0].empty()) return 0;

   int ship_num = 0;
   const int cols = board[0].size();
   if (board[0][0] == 'X' && cols != 1 && board[0][1] == '.') ship_num++;
   if (board[0][cols - 1] == 'X') ship_num++;
   for (int i = 1; i < cols - 1; ++i) {
      if (board[0][i] == 'X' && board[0][i + 1] == '.') {
         ship_num++;
      }
   }

   const int rows = board.size();
   for (int j = 1; j < rows; ++j) {
      for (int i = 0; i < cols; ++i) {
         if (board[j - 1][i] == 'X') continue;
         if (board[j][i] == 'X') {
            if (i != cols - 1 && board[j][i + 1] == '.') ship_num++;
            else if (i == cols - 1) ship_num++;
         }
      }
   }
   return ship_num;
}

int main()
{
   vector<vector<char>> board = {
      {'X'}, {'X'}
      //{ 'X', '.', '.', 'X' },
      //{ '.', '.', '.', 'X' },
      //{ '.', '.', '.', 'X' }
   };
   cout << countBattleships( board ) << endl;
   return 0;
}