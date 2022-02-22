// Spidey Sense

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

void solve()
{
    int m, n;
    cin>>m>>n;

    char matrix[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cin>>matrix[i][j];
    }

    vector<vector<int>> res(m, vector<int>(n, INT_MAX));

    queue<pair<int, int>> bomb;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j] == 'B')
                bomb.push({i, j});
        }
    }
    int count=0;
    while(!bomb.empty())
    {
        count++;
        int len = bomb.size();
        for(int i=0; i<len; i++)
        {
            pair<int, int> temp = bomb.front();
            bomb.pop();

            int x=temp.first-1, y=temp.second;
                
            if(x>=0 && y>=0 && x<M && y<N)
            {
                if(matrix[x][y] == 'O')
                {
                    if(res[x][y]==INT_MAX)
                        bomb.push({x, y});
                    res[x][y] = min(res[x][y], count);
                }
            }
                
            x=temp.first; y=temp.second-1;
            if(x>=0 && y>=0 && x<M && y<N)
            {
                if(matrix[x][y] == 'O')
                {
                    if(res[x][y]==INT_MAX)
                        bomb.push({x, y});
                    res[x][y] = min(res[x][y], count);
                }
            }
                
            x=temp.first; y=temp.second+1;
            if(x>=0 && y>=0 && x<M && y<N)
            {
                if(matrix[x][y] == 'O')
                {
                    if(res[x][y]==INT_MAX)
                        bomb.push({x, y});
                    res[x][y] = min(res[x][y], count);
                }
            }
                
            x=temp.first+1; y=temp.second;
            if(x>=0 && y>=0 && x<M && y<N)
            {
                if(matrix[x][y] == 'O')
                {
                    if(res[x][y]==INT_MAX)
                        bomb.push({x, y});
                    res[x][y] = min(res[x][y], count);
                }
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j] == 'W')
                res[i][j] = -1;
            else if(matrix[i][j] == 'B')
                res[i][j] = 0;
            else if(res[i][j] == INT_MAX)
                res[i][j] = -1;
        }
    }

    return;
}

int main(){
    solve();
    return 0;
}