// Find all pairs with given sum

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

vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        sort(A, A+N);
        sort(B, B+M);
        
        vector<pair<int, int>> ans;
        int i=0, j=M-1;
        while(i<N && j>=0)
        {
            if(A[i] + B[j] == X){
                ans.push_back({A[i], B[j]});
                i++;
                j--;
            }
            else if(A[i] + B[j] > X)
                j--;
            else
                i++;
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