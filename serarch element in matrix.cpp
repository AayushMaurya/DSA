// search element in sorted matrix

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
    int m, n, target;
    cin>>m>>n>>target;

    vector<vector<int>> matrix;

    for(int i=0 ; i<m ; i++)
    {
        vector<int> temp;
        for(int j=0 ; j<n ; j++)
        {
            int a;
            cin>>a;
            temp.pb(a);
        }
        matrix.pb(temp);
    }

    if(matrix[0][0] > target){
            cout<<"false";
            return;
        }
        
        int i=0;
        while(i<matrix.size())
        {
            if(matrix[i][0] > target)
                break;
            i++;
        }
        
        i--;
        
        for(int j=0 ; j<matrix[i].size() ; j++)
        {
            if(matrix[i][j] == target)
            {
                cout<<"true";
                return;
            }

        }
        cout<<"false";

        return;
}

int main()
{
	solve();
	return 0;
}