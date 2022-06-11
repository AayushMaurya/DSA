// circular tour

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

int tour(petrolPump p[],int n)
    {
        int start=0;
        int sum=0;
        int temp=0;
        for(int i=0; i<n; i++)
        {
            sum = sum + p[i].petrol - p[i].distance;
            if(sum<0)
            {
                start=1+i;
                temp += sum;
                sum=0;
            }
        }
        if(temp + sum >= 0)
            return start;
        return -1;
    }

int main() {

int t;
cin>>t;
 for(int i=0; i<t; i++)
    solve(i+1);

return 0;
}