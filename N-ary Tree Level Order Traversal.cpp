// N-ary Tree Level Order Traversa

#include<bits/stdc++.h>
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

vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> res;
            
            for(int i=0; i<n; i++)
            {
                Node* node = q.front();
                q.pop();
                res.push_back(node->val);
                
                for(auto itr: node->children)
                    q.push(itr);
                
            }
            ans.push_back(res);
        }
        
        return ans;
        
    }