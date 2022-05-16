// Permutations of a given string

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


void helper(string s, int i, vector<string>& ans)
    {
        if(i==s.size())
        {
            ans.push_back(s);
            return;
        }
        for(int j=i; j<s.size(); j++)
        {
            string temp = s;
            char t=temp[i];
            temp[i]=temp[j];
            temp[j]=t;
            if(i!=j && temp[i] == temp[j])
                continue;
            helper(temp, i+1, ans);
        }
        return;
    }
        vector<string>find_permutation(string S)
        {
            vector<string> ans;
            helper(S, 0, ans);
            sort(ans.begin(), ans.end());
            return ans;
        }

int main(){
    
    int n;
    cin>>n;
vector<vector<int>> vec(n, vector<int>(n));
for(int i=0; i<n; i++)
    cin>>vec[i][0]>>vec[i][1];

cout<<solve(vec, n, n)<<endl;
    return 0;
}