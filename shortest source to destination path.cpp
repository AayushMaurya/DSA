// Shortest ource to destination path

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

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        if(A[0][0]==0)return -1;
       if(A[X][Y]==0)return -1;
        
        if(X==0 && Y==0)
            return 0;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        A[0][0] = 0;
        int ans=0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x==X && y==Y)
                    return ans;
                
                if(x+1<N && A[x+1][y]==1){
                    q.push({x+1, y});
                    A[x+1][y] = 0;
                }
                if(x-1>=0 && A[x-1][y]==1){
                    q.push({x-1, y});
                    A[x-1][y] = 0;
                }
                if(y-1>=0 && A[x][y-1]==1){
                    q.push({x, y-1});
                    A[x][y-1] = 0;
                }
                if(y+1<M && A[x][y+1]==1){
                    q.push({x, y+1});
                    A[x][y+1] = 0;
                }
            }
            ans++;
        }
        return -1;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}