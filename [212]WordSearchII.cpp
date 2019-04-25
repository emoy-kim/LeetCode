/*
 * 
 * Given a 2D board and a list of words from the dictionary, find all words in the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell, 
 * where "adjacent" cells are those horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once in a word.
 * 
 *  
 * 
 * Example:
 * 
 * Input: 
 * board = [
 *   ['o','a','a','n'],
 *   ['e','t','a','e'],
 *   ['i','h','k','r'],
 *   ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * 
 * Output: ["eat","oath"]
 *  
 * 
 * Note:
 * 
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct WordTree
{
   string word;
   WordTree* letters[26];

   WordTree()
   {
      for (auto& letter : letters) {
         letter = nullptr;
      }
   }
};

WordTree* buildWordTree(const vector<string>& words)
{
   auto* tree = new WordTree;
   for (const auto& word : words) {
      WordTree* node = tree;
      for (const auto& c : word) {
         const int c_index = c - 'a';
         if (!node->letters[c_index]) {
            node->letters[c_index] = new WordTree;
         }
         node = node->letters[c_index];
      }
      node->word = word;
   }
   return tree;
}

void dfs(vector<string>& found, vector<vector<char>>& board, WordTree* root, const int& i, const int& j)
{
   const char c = board[j][i];
   const int c_index = c - 'a';
   if (c == '#' || !root->letters[c_index]) return;

   root = root->letters[c_index];
   if (!root->word.empty()) {
      found.push_back( root->word );
      root->word.clear();
   }

   board[j][i] = '#';
   if (i > 0) dfs( found, board, root, i - 1, j );
   if (i < static_cast<int>(board[0].size()) - 1) dfs( found, board, root, i + 1, j );
   if (j > 0) dfs( found, board, root, i, j - 1 );
   if (j < static_cast<int>(board.size()) - 1) dfs( found, board, root, i, j + 1 );  
   board[j][i] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
   WordTree* root = buildWordTree( words );

   const int row = board.size();
   const int col = board[0].size();
   
   vector<string> found;
   for (int j = 0; j < row; ++j) {
      for (int i = 0; i < col; ++i) {
         dfs( found, board, root, i, j );
      }
   }

   sort( found.begin(), found.end() );
   return found;
}

int main()
{
   vector<vector<char>> board = {
      { 'o', 'a', 'a', 'n' },
      { 'e', 't', 'a', 'e' },
      { 'i', 'h', 'k', 'r' },
      { 'i', 'f', 'l', 'v' }
   };
   vector<string> words = { "oath","pea","eat","rain" };
   vector<string> found = findWords( board, words );
   for (const auto& w : found) {
      cout << w.c_str() << " ";
   }
   cout << endl;
   return 0;
}