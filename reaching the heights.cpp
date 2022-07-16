// Reaching the heights

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
# define pii pair<int, int>
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

vector<int> reaching_height(int n, int a[]) {
    sort(a, a+n);
    
    vector<int> ans;
    int start=0, end=n-1;
    if(n==1)
        return {a[0]};
    if(a[start] == a[end])
    {
        return {-1};
    }
    int flag=1;
    
    while(start<=end)
    {
        if(flag==1)
        {
            ans.push_back(a[end]);
            end--;
        }
        else{
            ans.push_back(a[start]);
            start++;
        }
        flag = !flag;
    }
    return ans;
}