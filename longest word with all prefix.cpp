// Longest word withh all prefixes

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

class Trei
{
private:
    Node* root;
public:
    Trei(){
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

    bool checkIfPrefix(string word)
    {
        bool flag = true;
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if(!node->flag)
                    return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
};

string completeString(vector<string>& a, int n)
{
    Trei trie;
    for(auto &s: a)
    {
        trie.insert(s);
    }

    string ans = "";

    for(auto &s: a)
    {
        if(trie.checkIfPrefix(s))
        {
            if(s.length() > ans.length())
                ans = s;
            else if(s.length() == ans.length() && s<ans)
                ans = s;
        }
    }

    if(ans == "")
        return "None";
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<string> str(n);
    for(int i=0; i<n; i++)
        cin>>str[i];

    string ans = completeString(str, n);

    cout<<ans<<endl;

    return 0;
}