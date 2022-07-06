// Build a tree from string

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
    int data;
    struct Node* left;
    struct Node* right;

    Node (int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream(str);

    for(string str; iss >> str;)
        ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));

    queue<Node*> q;

    q.push(root);

    int i=1;
    while(!q.empty() && i<ip.size())
    {
        Node* currNode = q.front();
        q.pop();

        string currVal = ip[i];

        if(currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));

            q.push(currNode->left);
        }
        
        i++;
        if(i>=ip.size())
        {
            break;
        }
        currVal = ip[i];

        if(currVal!="N")
        {
            currNode->right = new Node(stoi(currVal));

            q.push(currNode->right);
        }
        i++;
    }
    return root;
}

int main()
{
    string str;
    cin>>str;

    Node* head = buildTree(str);

    return 0;
}