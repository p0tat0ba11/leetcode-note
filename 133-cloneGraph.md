# 133. Clone Graph

## Method
```cpp=
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

class Solution {
public:
    Node* clone(Node* node, unordered_map<Node*, Node*>& appear) {
        if(!node) return nullptr;
        if(appear.find(node) != appear.end()) return appear[node];
        Node* newNode = new Node(node->val);
        appear[node] = newNode;
        for(Node* neighbors: node->neighbors)
            newNode->neighbors.push_back(clone(neighbors, appear));
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> appear;
        return clone(node, appear);
    }
};
```