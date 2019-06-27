/*
 * https://leetcode.com/problems/range-sum-of-bst/
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int rangeSumBST(TreeNode* root, int L, int R) 
{
   if (!root) return 0;

   int sum = 0;
   queue<TreeNode*> visit;
   visit.push( root );
   while (!visit.empty()) {
      TreeNode* node = visit.front();
      visit.pop();

      if (L <= node->val && node->val <= R) sum += node->val;
      if (node->left != nullptr) visit.push( node->left );
      if (node->right != nullptr) visit.push( node->right );
   }
   return sum;
}