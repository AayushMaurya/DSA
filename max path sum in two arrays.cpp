// Max path sum in two arrays

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


int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int a=0, b=0;
        int ans=0;
        int sum1=0, sum2=0;
        while(a<l1 && b<l2)
        {
            if(A[a]<B[b])
                sum1+=A[a++];
            else if(A[a]>B[b])
                sum2+=B[b++];
            else
            {
                // cout<<sum1<<" "<<sum2<<" "<<endl;
                ans+=max(sum1, sum2)+A[a];
                a++;
                b++;
                sum1=0;
                sum2=0;
            }
        }
            while(a<l1)
            {
                sum1+=A[a];
                a++;
            }
            while(b<l2)
            {
                sum2+=B[b];
                b++;
            }
            ans+=max(sum1, sum2);
            return ans;
    }

int main(){
    
    int n;
    cin>>n;
vector<vector<int>> vec(n, vector<int>(n));
for(int i=0; i<n; i++)
    cin>>vec[i][0]>>vec[i][1];

cout<<solve(vec, n, n)<<endl;
    return 0;
}