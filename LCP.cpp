// LCP

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

string LCP(string ar[], int n)
    {
        string temp=ar[0];
        for(int i=1; i<n; i++)
            if(ar[i].length() < temp.length())
                temp=ar[i];
                
        int i;
        for(i=1; i<=temp.length(); i++)
        {
            int flag=0;
            for(int j=0; j<n; j++)
            {
                if(ar[j].substr(0, i) != temp.substr(0, i)){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        
        if(i==1)
            return "-1";
        return temp.substr(0, i-1);
    }

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<LCP(arr, n)<<endl;
    return 0;
}