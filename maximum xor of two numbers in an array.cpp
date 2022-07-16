// Maximum XOR of two numbers in an array
// using trie

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
    
    void insert(Node* node, int num)
    {
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            if(!node->links[bit])
                node->links[bit] = new Node();
            node = node->links[bit];
        }
    }
    
    int getMax(Node* node, int num)
    {
        int ans=0;
        
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            if(node->links[1-bit]){
                ans = ans | (1<<i);
                node = node->links[1-bit];
            }
            else
                node = node->links[bit];
        }
        
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        
        for(auto itr: nums)
        {
            insert(root, itr);
        }
        
        int ans = 0;
        
        for(auto itr: nums)
        {
            ans = max(ans, getMax(root, itr));
        }
        
        return ans;
    }