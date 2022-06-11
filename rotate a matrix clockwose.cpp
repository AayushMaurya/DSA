// rotate a matrix clock-wise

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

vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        int l=0;
        int r=N-1;
        int t=0;
        int b=M-1;
        
        while(l<r && t<b)
        {
            int x = Mat[t+1][l];
            for(int i=l; i<=r; i++)
            {
                swap(x, Mat[t][i]);
            }
            t++;
            for(int i=t; i<=b; i++)
            {
                swap(x, Mat[i][r]);
            }
            r--;
            for(int i=r; i>=l; i--)
            {
                swap(x, Mat[b][i]);
            }
            b--;
            for(int i=b; i>=t; i--)
            {
                swap(x, Mat[i][l]);
            }
            l++;
        }
        return Mat;
        
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}