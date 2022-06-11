// Unique rows in boolean matrix

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

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    set<vector<int>> st;
    vector<vector<int>> ans;
    int prev=0;
    for(int i=0; i<row; i++)
    {
        vector<int> temp;
        for(int j=0; j<col; j++)
        {
            temp.push_back(M[i][j]);
        }
        st.insert(temp);
        if(st.size() != prev)
            ans.push_back(temp);
        prev=st.size();
    }
    // for(auto itr: st)
    //     ans.push_back(itr);
    return ans;
}

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}