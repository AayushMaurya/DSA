// Valid Palindrome

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

bool isPalindrome(string s) {
        string str = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                s[i] = (char)(s[i] + 32);
            
            if(s[i]<='z' && s[i]>='a')
                str += s[i];
            else if(s[i]>='0' && s[i]<='9')
                str += s[i];
            
        }
        cout<<str<<endl;
        int n = str.size();
        
        if(n <= 1)
            return true;
        cout<<n<<endl;
        int left, right;
        
        if(n%2==0)
        {
            right = n/2;
            left = right-1;
        }
        else{
            right = n/2;
            left = n/2;
        }
        
        cout<<left<<" "<<right<<endl;
        
        while(left>=0 && right<n)
        {
            if(str[left]!=str[right])
                return false;
            left--;
            right++;
        }
        
        return true;
    }