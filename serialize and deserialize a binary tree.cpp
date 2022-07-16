// Serialize and Deserialize Binary Tree

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

vector<string> getVal(string str)
    {
        vector<string> ans;
        string res;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] == ',')
            {
                ans.push_back(res);
                res = "";
            }
            else{
                res += str[i];
            }
        }
        // ans.push_back(res);
        
        return ans;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL)
                ans += "#,";
            else{
                ans += (to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        vector<string> s = getVal(data);
        int index=0;
        TreeNode* root = new TreeNode(stoi(s[index]));
        index++;
        
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(s[index] == "#")
            {
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(s[index]));
                node->left = leftNode;
                q.push(leftNode);
            }
            index++;
            
            if(s[index] == "#")
            {
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(s[index]));
                node->right = rightNode;
                q.push(rightNode);
            }
            index++;
        }
     return root;   
    }