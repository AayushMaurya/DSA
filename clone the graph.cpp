// clone the graph

include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
ll max(ll x, ll y)
{
    return (x>y)?x:y;
}
ll min(ll x, ll y)
{
    return (x>y)?y:x;
}
void swap(ll *x, ll *y)
{
    ll temp = *x;
    *x = *y;
    *y = temp;
}

// **********************************

void solve(Node* node, Node* copy, vector<Node*>& vis)
    {
        vis[copy->val] = copy;
        for(auto child: node->neighbors)
        {
            if(vis[child->val] == NULL)
            {
                Node* temp = new Node(child->val);
                copy->neighbors.push_back(temp);
                solve(child, temp, vis);
            }
            else{
                copy->neighbors.push_back(vis[child->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        
        Node* copy = new Node(node->val);
        vector<Node*> vis(1000, NULL);
        
        solve(node, copy, vis);
        
        return copy;
    }
