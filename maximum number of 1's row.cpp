// Maximum number of 1's row

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

int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            int i=0, j=M-1;
            int ans=0;
            int count=0;
            int prev=count;
            while(i<N && j>=0)
            {
                while(Mat[i][j]==1 && j>=0){
                    count++;
                    j--;
                }
                if(count>prev)
                    ans=i;
                prev=count;
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