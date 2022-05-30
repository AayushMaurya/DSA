// 4 Sum

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

vector<vector<int> > fourSum(vector<int> &arr, int target) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int sum = target-arr[i]-arr[j];
                int l=j+1,r=n-1;
                while(l<r)
                {
                    if(arr[l] + arr[r] == sum)
                    {
                        vector<int> temp(4);
                        temp[0] = arr[i];
                        temp[1] = arr[j];
                        temp[2] = arr[l];
                        temp[3] = arr[r];
                        ans.push_back(temp);
                        while(l+1<n && arr[l] == arr[l+1])  l++;
                        l++;
                        r--;
                    }
                    else{
                        if(arr[l]+arr[r] < sum)
                            l++;
                        else
                            r--;
                    }
                }
                while(j+1<n && arr[j]==arr[j+1])    j++;
            }
            while(i+1<n && arr[i]==arr[i+1])    i++;
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