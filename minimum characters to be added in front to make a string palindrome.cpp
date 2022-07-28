// minimum characters to be added at front to make string palindrome

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

int main()
{
    string str;
    cin>>str;

    int n = str.size();
    
    int ans=0;
    int left=0, right = n-1;

    while(left<right)
    {
        if(str[left] == str[right])
        {
            left++;
            right--;
        }

        else{
            left = 0;
            ans = n-right;

            while(str[left] == str[right])
            {
                ans--;
                left++;
            }
            right--;
        }
    }

    cout<<ans<<endl;

    return 0;
}