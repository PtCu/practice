/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> visited;
    // Node *cloneGraph(Node *node)
    // {
    //     if (!node)
    //         return nullptr;
    //     if (visited.find(node) != visited.end())
    //         return visited[node];
    //     Node *clone_node = new Node(node->val);
    //     visited[node] = clone_node;
    //     for (auto &n : node->neighbors)
    //     {
    //         clone_node->neighbors.emplace_back(cloneGraph(n));
    //     }
    //     return clone_node;
    // }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        queue<Node *> Q;
        Q.push(node);
        visited[node] = new Node(node->val);
        while (!Q.empty())
        {
            auto p = Q.front();
            Q.pop();
            for (auto &n : p->neighbors)
            {
                //没有访问过该结点就访问并拷贝
                if (visited.find(n) == visited.end())
                {
                    visited[n] = new Node(n->val);
                    Q.push(n);
                }
                //访问过该结点，但是仍有边；或没访问过有边
                visited[p]->neighbors.emplace_back(visited[n]);
            }

           
        }
        return visited[node];
    }
};
// @lc code=end
