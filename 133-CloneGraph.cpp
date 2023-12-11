// 133 - Clone Graph (LeetCode Exercise)

// Time Complexity: O(|node| + |neighbors|)
// Space Complexity: O(|node|)

#include <vector>
#include <map>

class Node 
{
public:
    int val;
    std::vector<Node*> neighbors;
    Node() 
    {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) 
    {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) 
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* clone(Node* node, std::map<Node*, Node*>& oldToNew)
{
    if (!node) return nullptr;

    Node* copy = new Node(node->val);
    oldToNew[node] = copy;

    for (Node* neighbor : node->neighbors)
    {
        if (oldToNew.find(neighbor) != oldToNew.end())
        {
            copy->neighbors.push_back(oldToNew[neighbor]);
        }
        else
        {
            copy->neighbors.push_back(clone(neighbor, oldToNew));
        }
    }

    return copy;
}

Node* cloneGraph(Node* node) 
{
    std::map<Node*, Node*> oldToNew = {};
    return clone(node, oldToNew);
}