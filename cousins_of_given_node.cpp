//cousins of a given node

class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        queue<Node*> temp;
        vector<int> res;
        temp.push(root);
        int flag=0;
        while(temp.size()>0)
        {
            if(flag==1)
            {
                while(!temp.empty())
                {
                    res.push_back(temp.front()->data);
                    temp.pop();
                }
                break;
            }
            int n=temp.size();
            for(int i=0; i<n; i++)
            {
                auto node=temp.front();
                temp.pop();
                if(node->left==node_to_find || node->right==node_to_find)
                {
                    flag=1;
                    continue;
                }
                if(node->left)
                    temp.push(node->left);
                if(node->right)
                    temp.push(node->right);
            }
        }
        if(res.size()==0)
            res.push_back(-1);
        return res;
    }
};