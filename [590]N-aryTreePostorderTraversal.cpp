/*
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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

vector<int> postorder(Node* root) 
{
   if(root == nullptr) return {};

   vector<int> post;
   stack<Node*> visit;
   visit.push(root);
   while(!visit.empty()) {
      Node* node = visit.top();
      visit.pop();

      for (const auto& n : node->children) {
         visit.push( n );
      }
      post.insert( post.begin(), node->val );
   }
   return post;
}