// Number of distince substrings

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
    bool flag = false;
    Node* links[26];

    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }
};

class Trie
{
private: 
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }

    int insert(string word)
    {
        Node* node = root;
        int ans=0;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                ans++;
                node->put(word[i], new Node);
            }
            node = node->get(word[i]);
        }
        return ans;
    }
};

int count(string str)
{
    int ans=0;
    Trie trie;

    for(int i=0; i<str.size(); i++)
    {
        ans += trie.insert(str.substr(i));
    }

    return ans;
}

int main()
{
    string str;
    cin>>str;

    int ans = count(str);

    cout<<ans<<endl;

    return 0;
}