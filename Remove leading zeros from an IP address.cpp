// Remove leading zeros from an IP address

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

void solve()
{
    string s;
    cin>>s;

    string res="";
        string temp="";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '.')
            {
                int j=0;
                while(temp[j]=='0' && j<temp.size()-1)
                    j++;
                res+=(temp.substr(j, temp.size()-j));
                res+='.';
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        int j=0;
                while(temp[j]=='0' && j<temp.size()-1)
                    j++;
                res+=(temp.substr(j, temp.size()-j));
        cout<< res<<endl;
}

int main(){
    solve();
    return 0;
}