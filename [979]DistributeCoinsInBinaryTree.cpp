/*
 * https://leetcode.com/problems/distribute-coins-in-binary-tree/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int distribute(TreeNode* root, int& moves)
{
   if (root == nullptr) return 0;
   const int left = distribute( root->left, moves );
   const int right = distribute( root->right, moves );
   moves += abs( left ) + abs( right );
   return left + right + root->val - 1;
}

int distributeCoins(TreeNode* root) 
{
   int moves = 0;
   distribute( root, moves );
   return moves;
}

TreeNode* buildTree(vector<int>& nodes)
{
   auto* root = new TreeNode(nodes[0]);
   
   queue<TreeNode*> visit;
   visit.push( root );
   int index = 1;
   const int size = nodes.size();
   while (!visit.empty()) {
      TreeNode* node = visit.front();
      visit.pop();

      if (index < size && nodes[index] >= 0) {
         node->left = new TreeNode(nodes[index]);
         visit.push( node->left );
      }
      index++;
      if (index < size && nodes[index] >= 0) {
         node->right = new TreeNode(nodes[index]);
         visit.push( node->right );
      }
      index++;
   }
   return root;
}

int main()
{
   vector<int> nodes = { 0,2,3,0,0,-1,-1,1 };
   TreeNode* root = buildTree( nodes );
   cout << distributeCoins( root ) << endl;
   return 0;
}