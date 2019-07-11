/*
 * https://leetcode.com/problems/univalued-binary-tree/
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

bool isUnivalTree(TreeNode* root) 
{
   const int val = root->val;
   queue<TreeNode*> visit;
   visit.push( root );
   while (!visit.empty()) {
      auto* node = visit.front();
      visit.pop();
      
      if (node->val != val) return false;
      if (node->left != nullptr) visit.push( node->left );
      if (node->right != nullptr) visit.push( node->right );
   }
   return true;
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
   vector<int> nodes = { 1, 1, 1, 1, 1, 2 };
   TreeNode* root = buildTree( nodes );
   cout << isUnivalTree( root ) << endl;
   return 0;
}