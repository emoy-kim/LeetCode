/*
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (36.07%)
 * Total Accepted:    254.8K
 * Total Submissions: 706.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 * 
 */

#include <iostream>
#include <stack>
#include <set>

using namespace std;

struct TreeNode 
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
bool hasPathSum(TreeNode* root, int sum) 
{
   if (root == NULL) return false;

   stack<TreeNode*> nodes;
   nodes.push( root );
   int s = root->val;

   set<TreeNode*> visited;
   visited.insert( root );

   while (!nodes.empty()) {
      TreeNode* node = nodes.top();

      if (node->left == NULL && node->right == NULL) {
          if (s == sum) return true;
      }

      if (node->left != NULL && visited.find( node->left ) == visited.end()) {
          visited.insert( node->left );
          nodes.push( node->left );   
          s += node->left->val;
      }
      else if (node->right != NULL && visited.find( node->right ) == visited.end()) {
          visited.insert( node->right );
          nodes.push( node->right );
          s += node->right->val;
      }
      else {
          s -= node->val;
          nodes.pop();
      }
   }
   return false;
}