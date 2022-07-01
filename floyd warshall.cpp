// floyd warshall

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
# define vvi vector<vector<int>>
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

// set matrix[i][j] = INT_MAX in case of no edge between i and j

void floyd_warshall(vvi& matrix, int n)
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;
                else if(matrix[i][k] + matrix[k][j] < matrix[i][j])
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
}

int main()
{
    int n;
    cin>> n;

    vvi matrix(n, vector<int>(n));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }

    floyd_warshall(matrix, n);

    for (int i = 0; i < n; ++i)
    {
        for(int j=0; j<n; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}