// Stock buy and sell

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

vector<vector<int> > stockBuySell(vector<int> A, int n){
        int start = 0, end = 0;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++)
        {
            if(A[i]>A[end])
                end=i;
            else{
                vector<int> temp;
                if(end>start){
                    temp.push_back(start);
                    temp.push_back(end);
                
                    ans.push_back(temp);
                }
                start=i;
                end=i;
            }
        }
        if(end>start)
            {
                vector<int> temp;
                temp.push_back(start);
                    temp.push_back(end);
                
                    ans.push_back(temp);
            }
        return ans;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}