// Sub array with given sum

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

vector<int> subarraySum(int arr[], int n, long long s)
    {
        int i=0, j=0;
        long long sum=0;
        vector<int> ans;
        
        sum+=arr[j];
        while(j<n)
        {
            if(sum==s)
                break;
            else if(sum < s)
            {
                j++;
                if(j<n) sum+=arr[j];
            }
            else if(sum>s)
            {
                sum-=arr[i];
                i++;
            }
        }
        
        if(sum!=s)
            ans.push_back(-1);
        else
        {
            i++;
            j++;
            ans.push_back(i);
            ans.push_back(j);
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