// Robots

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

string solve()
{
    string s1, s2;
    cin>>s1>>s2;

    int n=s1.length();

    int i=0, j=0;

    while(i<n && j<n)
    {
        while(s1[i] == '#')
            i++;
        while(s2[j] == '#')
            j++;

        if(s1[i]!=s2[j])
            return "No";
        else if(s1[i] == 'A' && i<j)
            return "No";
        else if(s1[i] == 'B' && i>j)
            return "No";
        else{
            i++;
            j++;
        }
    }

    return "Yes";
}

int main(){
    cout<<solve()<<endl;
    return 0;
}