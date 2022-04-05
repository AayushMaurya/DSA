// Maximum Product of Increasing Subsequence of Size 3

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

vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        int sm[n];
        set<int> s;
        vector<int> res(3, -1);
        for(int i=0; i<n; i++)
        {
            auto obj = s.insert(arr[i]);
            auto add = obj.first;
            add--;
            if(add==s.end())    sm[i]=-1;
            else    sm[i]=*add;
        }
        
        long long int pro=INT_MIN;
        int mx = arr[n-1];
        for(int i=n-2; i>=1; i--)
        {
            if(arr[i] >= mx){
                mx = arr[i];
            }
            else if(sm[i] != -1){
                if(pro < (long long int)sm[i]*arr[i]*mx){
                    pro = (long long int)sm[i]*arr[i]*mx;
                    res[0] = sm[i];
                    res[1] = arr[i];
                    res[2] = mx;
                }
            }
        }
        return res;
    } 


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<solve(arr, n)<<endl;
    return 0;
}