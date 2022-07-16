// Maximum XOR With an Element From Array
// Using Trie

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

struct Node{
        Node* links[2];
    };
    
    void insert(Node* root, int num)
    {
        Node* node = root;
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            if(!node->links[bit])
                node->links[bit] = new Node();
            node = node->links[bit];
        }
    }
    
    int findMax(Node* root, int num)
    {
        Node* node = root;
        int ans=0;
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            if(node->links[1-bit])
            {
                ans = ans | (1<<i);
                node = node->links[1-bit];
            }
            else{
                node = node->links[bit];
            }
        }
        return ans;
    }
    
    int solve(vector<int> q, vector<int>& nums, Node* node)
    {
        if(q[0] < nums[0])
            return -1;
        
        int ans=findMax(node, q[1]);
        
        return ans;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<vector<int>> q(n, vector<int> (3));
        
        for(int i=0; i<n; i++)
        {
            q[i][0] = queries[i][1];
            q[i][1] = queries[i][0];
            q[i][2] = i;
        }
        
        sort(nums.begin(), nums.end());
        
        sort(q.begin(), q.end());
        
        Node* node = new Node();
        
        int j=0;
        vector<int> ans(n);
        int prev=-1;
        for(int i=0; i<n; i++){
            while(j<nums.size() && nums[j]<=q[i][0]){
                insert(node, nums[j]);
                j++;
            }
            ans[q[i][2]] = solve(q[i], nums, node);
        }
        
        return ans;
    }