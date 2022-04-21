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
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        unordered_map<Node*, Node*> mp;
        mp[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            
            for(auto x: temp->neighbors){
                if(mp.find(x) == mp.end()){
                    mp[x] = new Node(x->val);
                    q.push(x);
                }
                mp[temp]->neighbors.push_back(mp[x]);
            }
        }
        return mp[node];
        
    }
};