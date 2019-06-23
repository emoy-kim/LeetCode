/*
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
   int val;
   vector<Node*> children;

   Node() {}

   Node(int _val, vector<Node*> _children) 
   {
      val = _val;
      children = _children;
   }
};

vector<int> preorder(Node* root) 
{
   if(root == nullptr) return {};

   vector<int> pre;
   stack<Node*> visit;
   visit.push(root);
   while(!visit.empty()) {
      Node* node = visit.top();
      visit.pop();

      const int size = node->children.size();
      for (int i = size - 1; i >= 0; --i) {
         visit.push( node->children[i] );
      }
      pre.push_back( node->val );
   }
   return pre;
}