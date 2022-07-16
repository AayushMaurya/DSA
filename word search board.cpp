// Word search board

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

bool dfs(int index, int x, int y, vector<string>& A, string B)
{
    if(index == B.size())
        return true;
    
    if(B[index] != A[x][y])
        return false;
    int n = A.size(), m = A[0].size();
    
    if(x+1<n)
    {
        if(dfs(index+1, x+1, y, A, B))
            return true;
    }
    if(y+1<m)
    {
        if(dfs(index+1, x, y+1, A, B))
            return true;
    }
    if(x-1>=0)
    {
        if(dfs(index+1, x-1, y, A, B))
            return true;
    }
    if(y-1>=0)
    {
        if(dfs(index+1, x, y-1, A, B))
            return true;
    }
    
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[0].size(); j++)
        {
            if(A[i][j] == B[0])
            {
                if(dfs(0, i, j, A, B))
                    return 1;
            }
        }
    }
    return 0;
}