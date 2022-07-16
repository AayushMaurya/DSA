// Count of distince substrings
// without using Trie class

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
    Node* children[26];
};

int insert(Node* root, string word)
{
    Node* node = root;
    int ans=0;
    for(int i=0; i<word[i]; i++)
    {
        if(node->children[word[i]-'a'] == NULL)
        {
            ans++;
            node->children[word[i]-'a'] = new Node();
        }
        node = node->children[word[i]-'a'];
    }
    return ans;
}

int countDistinct(string s)
{
    int ans=1;
    Node* root = new Node();

    for(int i=0; i<s.size(); i++)
    {
        ans += insert(root, s.substr(i));
    }

    return ans;
}

int main()
{
    string str;
    cin>>str;

    int ans = countDistinct(str);

    cout<<ans<<endl;

    return 0;
}