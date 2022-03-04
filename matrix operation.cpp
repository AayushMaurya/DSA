// Matrix Operation

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
// ll max(ll x, ll y)
// {
//     return (x>y)?x:y;
// }
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
    int n, m;
    cin>>n>>m;

    int matrix[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>matrix[i][j];
    }

        int x=0, y=0;
        string direction="right";
        
        while(1)
        {
            // cout<<direction<<" "<<x<<" "<<y<<endl;
            if(matrix[x][y]==0)
            {
                if(direction=="right"){
                    if(x<0 || y<0 || x>=n || y+1>=m)
                        return {x, y};
                    else
                        y++;
                }
                else if(direction=="up")
                {
                    if(x-1<0 || y<0 || x>=n || y>=m)
                        return {x, y};
                    else
                        x--;
                }
                else if(direction=="left"){
                    if(x<0 || y-1<0 || x>=n || y>=m)
                        return {x, y};
                    else
                        y--;
                }
                else{
                    if(x<0 || y<0 || x+1>=n || y>m)
                        return {x, y};
                    else
                        x++;
                }
            }
            else
            {
                if(direction == "right")
                    direction="down";
                else if(direction=="left")
                    direction="up";
                else if(direction=="up")
                    direction="right";
                else if(direction == "down")
                    direction="left";
                matrix[x][y]=0;
            }
            
            // if(x<0 || y<0 || x>=n || y>m)
            //     return {x, y};
        }
}

int main(){
    solve();
    return 0;
}