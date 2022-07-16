// Maximum xor with an element from another array

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
    bool containsKey(int bit)
    {
        return links[bit]!=NULL;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node* node)
    {
        links[bit] = node;
    }

};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int num)
    {
        Node* node=root;
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit))
            {
                node->put(bit, new Node);
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node* node = root;
        int ans = 0;
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit))
            {
                ans = ans | (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return ans;
    }
};

int solve(int arr1[], int arr2[], int n, int m)
{
    Trie trie;

    for(int i=0; i<n; i++)
    {
        trie.insert(arr1[i]);
    }
    int ans=0;

    for(int i=0; i<m; i++)
    {
        ans = max(ans, trie.getMax(arr2[i]));
    }

    return ans;
}

int main()
{
    int n, m;
    cin>>n>>m;

    int arr1[n], arr2[m];

    for(int i=0; i<n; i++)
        cin>>arr1[i];
    for(int i=0; i<m; i++)
        cin>>arr2[i];

    int ans = solve(arr1, arr2, n, m);

    cout<<ans<<endl;

    return 0;

}