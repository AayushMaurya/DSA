//  Delete Columns to Make Sorted

#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            char ch = strs[0][i];
            bool flag = false;
            for(int j=0; j<strs.size(); j++)
            {
                if(strs[j][i] < ch){
                    flag = true;
                    break;
                }
                ch = strs[j][i];
            }
            if(flag)
                ans++;
        }
        return ans;
    }	
}

int main()
{
	solve();
	return 0;
}