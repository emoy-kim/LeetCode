/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (44.14%)
 * Total Accepted:    189.5K
 * Total Submissions: 429.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
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

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
   vector<vector<int>> result;
   if (root == NULL) return result;

   queue<TreeNode*> nodes;
   nodes.push( root );

   while (true) {
      vector<int> level;
      const int level_num = nodes.size();
      for (int i = 0; i < level_num; ++i) {
          TreeNode* node = nodes.front();
          nodes.pop();

          if (node == NULL) continue;
          level.push_back( node->val );

          nodes.push( node->left );
          nodes.push( node->right );
      }

      if (level.empty()) break;

      result.insert( result.begin(), level );
   }
   return result;
}