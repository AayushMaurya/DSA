// remove digits form number to maximize result

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

string removeDigit(string number, char digit) {
        string ans="0";
        // int mn=0;
        for(int i=0; i<number.size(); i++)
        {
            if(number[i]!=digit)    continue;
            if(number.substr(0, i)+number.substr(i+1, number.size()-i) > ans)
            {
                // mn=stoi(number.substr(0, i)+number.substr(i+1, number.size()-i));
                ans=number.substr(0, i)+number.substr(i+1, number.size()-i);
            }
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