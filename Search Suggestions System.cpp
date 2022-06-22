// Search Suggestions System

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
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

vector<vector<string>> suggestedProducts(vector<string>& products, string str) {
        
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        
        vector<bool> isvalid(products.size(), true);
        
        string curr="";
        for(int i=0; i<str.size(); i++)
        {
            vector<string> res;
            curr += str[i];
            for(int j=0; j<products.size(); j++)
            {
                if(i>=products[j].size())
                    continue;
                
                if(products[j].substr(0, curr.size()) == curr)
                    res.push_back(products[j]);
                
                if(res.size() == 3)
                    break;
            }
            
            ans.push_back(res);
        }
        return ans;
    }