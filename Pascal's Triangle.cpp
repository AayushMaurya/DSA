// Pascal's Triangle
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


 vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++)
        {
            vector<int> temp(i);
            if(i==1)
                temp[0]=1;
            else{
                temp[0]=1;
                temp[i-1]=1;
                for(int j=1; j<i-1; j++)
                    temp[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            ans.push_back(temp);
        }
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