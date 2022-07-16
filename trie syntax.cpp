// Syntax of trie

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

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }

    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag = true;
    }
};

class Trie{
private:
    Node* root;
public: 
    Trie(){
        root = new Node();
    }

    void insert(string word)
    {
        Node* node = root;

        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->flag;
    }

    bool startsWith(string word)
    {
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return true;
    }
};

int main()
{
    Trie ds;
    ds.insert("apple");
    ds.insert("apps");
    ds.insert("bca");

    cout<<ds.search("apple")<<endl;
    cout<<ds.search("app")<<endl;
    cout<<ds.startsWith("apps")<<endl;
    return 0;
}