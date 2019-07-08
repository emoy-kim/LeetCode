/*
 * https://leetcode.com/problems/merge-two-binary-trees/
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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{
   if (t1 == nullptr && t2 == nullptr) return nullptr;

   auto* root = new TreeNode(0);
   queue<TreeNode*> visit, visit1;
   if (t1 != nullptr) {
      visit1.push( t1 );
      visit.push( root );
   }
   while (!visit1.empty()) {
      TreeNode* node = visit.front();
      TreeNode* ref_node = visit1.front();
      visit.pop();
      visit1.pop();
      
      node->val += ref_node->val;
      if (ref_node->left != nullptr) {
          visit1.push( ref_node->left );
          node->left = new TreeNode(0);
          visit.push( node->left );
      }
      if (ref_node->right != nullptr) {
          visit1.push( ref_node->right );
          node->right = new TreeNode(0);
          visit.push( node->right );
      }
   }

   queue<TreeNode*> visit2;
   if (t2 != nullptr) {
      visit2.push( t2 );
      visit.push( root );
   }
   while (!visit2.empty()) {
      TreeNode* node = visit.front();
      TreeNode* ref_node = visit2.front();
      visit.pop();
      visit2.pop();
      
      node->val += ref_node->val;
      if (ref_node->left != nullptr) {
          visit2.push( ref_node->left );
          if (node->left == nullptr) node->left = new TreeNode(0);
          visit.push( node->left );
      }
      if (ref_node->right != nullptr) {
          visit2.push( ref_node->right );
          if (node->right == nullptr) node->right = new TreeNode(0);
          visit.push( node->right );
      }
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
   vector<int> node1 = { 1, 3, 2, 5 };
   vector<int> node2 = { 2, 1, 3, -1, 4, -1, 7 };
   TreeNode* t1 = buildTree( node1 );
   TreeNode* t2 = buildTree( node2 );
   printTreeNodes( mergeTrees( t1, t2 ) );
   return 0;
}