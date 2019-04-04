/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (25.70%)
 * Total Accepted:    206.3K
 * Total Submissions: 801.7K
 * Testcase Example:  '{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}'
 *
 * Given a reference of a node in a connected undirected graph, return a deep
 * copy (clone) of the graph. Each node in the graph contains a val (int) and a
 * list (List[Node]) of its neighbors.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * {"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}
 * 
 * Explanation:
 * Node 1's value is 1, and it has two neighbors: Node 2 and 4.
 * Node 2's value is 2, and it has two neighbors: Node 1 and 3.
 * Node 3's value is 3, and it has two neighbors: Node 2 and 4.
 * Node 4's value is 4, and it has two neighbors: Node 1 and 3.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes will be between 1 and 100.
 * The undirected graph is a simple graph, which means no repeated edges and no
 * self-loops in the graph.
 * Since the graph is undirected, if node p has node q as neighbor, then node q
 * must have node p as neighbor too.
 * You must return the copy of the given node as a reference to the cloned
 * graph.
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

class Node 
{
public:
   int val;
   vector<Node*> neighbors;
   
   Node() {}
   
   Node(int _val, vector<Node*> _neighbors) 
   {
      val = _val;
      neighbors = _neighbors;
   }
};
    
Node* cloneGraph(Node* node) 
{
   if (node == nullptr) return node;

   unordered_map<Node*, Node*> visited;
   visited[node] = new Node;
   visited[node]->val = node->val;

   deque<Node*> bfs = { node };
   while (!bfs.empty()) {
      Node* ptr = bfs.front();
      bfs.pop_front();
      
      for (const auto& n : ptr->neighbors) {
         if (visited.find( n ) == visited.end()) {
            bfs.push_back( n );
            visited[n] = new Node;
            visited[n]->val = n->val;
         }
         visited[ptr]->neighbors.push_back( visited[n] );
      }
   }
   return visited[node];
}

int main()
{
   Node* node1 = new Node; 
   Node* node2 = new Node; 
   Node* node3 = new Node; 
   Node* node4 = new Node; 
   node1->val = 1; node1->neighbors = { node2, node4 };
   node2->val = 2; node2->neighbors = { node1, node3 };
   node3->val = 3; node3->neighbors = { node2, node4 };
   node4->val = 4; node4->neighbors = { node1, node3 };

   Node* cloned = cloneGraph( node1 );
  
   return 0;
}