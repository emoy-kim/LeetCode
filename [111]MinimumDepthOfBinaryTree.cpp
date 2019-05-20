/*
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (34.22%)
 * Total Accepted:    248.3K
 * Total Submissions: 725.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
 * 
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode 
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) 
{
   if (root == NULL) return 0;
   int left_depth = minDepth( root->left );
   int right_depth = minDepth( root->right );
   if (left_depth + right_depth == 0) return 1;

   if (left_depth == 0) left_depth = INT_MAX;
   if (right_depth == 0) right_depth = INT_MAX;
   return 1 + min( left_depth, right_depth );
}