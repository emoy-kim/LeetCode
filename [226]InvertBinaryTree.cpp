/*
 * https://leetcode.com/problems/invert-binary-tree/
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

TreeNode* invertTree(TreeNode* root) 
{
   if (root != nullptr) {
      invertTree( root->left );
      invertTree( root->right );
      swap( root->left, root->right );
   }
   return root;
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

void printTreeNodes(TreeNode* root)
{
   queue<TreeNode*> visit;
   visit.push( root );

   while (!visit.empty()) {
      TreeNode* node = visit.front();
      visit.pop();

      cout << node->val << " ";
      if (node->left != nullptr) visit.push( node->left );
      if (node->right != nullptr) visit.push( node->right );
   }
   cout << endl;
}

int main()
{
   vector<int> nodes = { 4,2,7,1,3 };
   TreeNode* root = buildTree( nodes );
   printTreeNodes( invertTree( root ) );
   return 0;
}