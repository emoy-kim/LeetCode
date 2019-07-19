/*
 * https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* recoverFromPreorder(string S) 
{
   stack<TreeNode*> visit;
   for (size_t i = 0; i < S.length();) {
      size_t level = 0;
      while (S[i] == '-') {
          i++; 
          level++;
      }
      
      size_t length = 0;
      while (i < S.length() && S[i] != '-') {
          i++;
          length++;
      }
      
      auto* node = new TreeNode(stoi( S.substr( i - length, length ) ));
      while (visit.size() > level) {
          visit.pop();
      }
      if (!visit.empty()) {
          auto* parent = visit.top();
          if (parent->left == nullptr) parent->left = node;
          else parent->right = node;
      }
      visit.push( node );
   }
   while (visit.size() > 1) visit.pop();
   return visit.top();
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
   const string S = "1-2--3--4-5--6--7";
   printTreeNodes( recoverFromPreorder( S ) );
   return 0;
}