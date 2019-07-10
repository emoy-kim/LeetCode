/*
 * https://leetcode.com/problems/delete-nodes-and-return-forest/
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* deleteNodes(
   vector<TreeNode*>& cut_trees, 
   TreeNode* node, 
   const unordered_set<int>& deleted_set,
   const bool is_from_root
)
{
   if (node == nullptr) return nullptr;
   const bool is_to_be_deleted = deleted_set.find( node->val ) != deleted_set.end();
   if (is_from_root && !is_to_be_deleted) cut_trees.push_back( node );
   node->left = deleteNodes( cut_trees, node->left, deleted_set, is_to_be_deleted );
   node->right = deleteNodes( cut_trees, node->right, deleted_set, is_to_be_deleted );
   return is_to_be_deleted ? nullptr : node;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
{
   vector<TreeNode*> cut_trees;
   unordered_set<int> deleted_set;
   for (const auto& d : to_delete) {
      deleted_set.insert( d );
   }
   deleteNodes( cut_trees, root, deleted_set, true );
   return cut_trees;
}