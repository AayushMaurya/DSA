// Alien Dictionary

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

string findOrder(string dict[], int N, int k) {
        
        vector<int> adj[k], indegree(k, 0);
        
        for(int i=0; i<N-1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int j=0;
            
            while(s1[j]!='\0' && s2[j]!='\0')
            {
                if(s1[j] == s2[j])
                    j++;
                else{
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    indegree[s2[j]-'a']++;
                    break;
                }
            }
        }
        
        // topological sorting
        
        queue<int> q;
        
        for(int i=0; i<k; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        string ans="";
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            ans += (char)(cur+'a');
            
            for(int i=0; i<adj[cur].size(); i++)
            {
                indegree[adj[cur][i]]--;
                if(indegree[adj[cur][i]] == 0)
                    q.push(adj[cur][i]);
            }
        }
        return ans;
    }