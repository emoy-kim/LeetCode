/*
 * https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
 */

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bstToGst(TreeNode* root) 
{
   if (!root) return root;

   vector<int> table(101, 0);
   queue<TreeNode*> visit;
   visit.push( root );
   while (!visit.empty()) {
      TreeNode* node = visit.front();
      visit.pop();
      
      table[node->val] += node->val;
      if (node->left != nullptr) visit.push( node->left );
      if (node->right != nullptr) visit.push( node->right );
   }

   visit.push( root );
   while (!visit.empty()) {
      TreeNode* node = visit.front();
      visit.pop();
      
      node->val = accumulate( table.begin() + node->val, table.end(), 0 );
      if (node->left != nullptr) visit.push( node->left );
      if (node->right != nullptr) visit.push( node->right );
   }
   return root;
}