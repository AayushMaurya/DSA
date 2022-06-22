// Determine Whether Matrix Can Be Obtained By Rotation

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

 bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool a = true;
        bool b = true;
        bool c = true;
        bool d = true;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]!=target[i][j])
                    a=false;
                if(mat[i][j]!=target[n-j-1][i])
                    b=false;
                if(mat[i][j]!=target[n-i-1][n-j-1])
                    c=false;
                if(mat[i][j]!=target[j][n-i-1])
                    d=false;
            }
        }
        return a || b || c || d;
    }