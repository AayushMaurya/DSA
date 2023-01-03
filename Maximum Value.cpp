// Maximum Value

#include <bits/stdc++.h>
using namespace std;

vector<int> maximumValue(Node* node) {
        vector<int> res;
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            int n = q.size();
            int maxVal = q.front()->data;
            for(int i=0; i<n; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                    
                if(node->data > maxVal)
                    maxVal = node->data;
            }
            res.push_back(maxVal);
        }
        return res;
    }