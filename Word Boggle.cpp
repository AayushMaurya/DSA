// Word Boggle

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

bool dfs(int index, string word, int x, int y, vector<vector<char> >& board, vector<vector<bool>>& vis)
    {
        if(index == word.size())
            return true;
        if(x>=board.size() || y>=board[0].size() || x<0 || y<0 || word[index]!=board[x][y] || vis[x][y])
            return false;
            
        vis[x][y] = true;
        
        if(dfs(index+1, word, x-1, y-1, board, vis) || 
            dfs(index+1, word, x-1, y, board, vis) ||
            dfs(index+1, word, x-1, y+1, board, vis) ||
            dfs(index+1, word, x, y-1, board, vis) || 
            dfs(index+1, word, x, y+1, board, vis) ||
            dfs(index+1, word, x+1, y-1, board, vis) ||
            dfs(index+1, word, x+1, y, board, vis) || 
            dfs(index+1, word, x+1, y+1, board, vis))
            return true;
            
        vis[x][y] = false;
        
        return false;
    }

    bool isPresent(string str, vector<vector<char> >& board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == str[0]){
                    if(dfs(0, str, i, j, board, vis))
                        return true;
                }
            }
        }
        return false;
    }
    
    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
        
        vector<string> ans;
        
        for(auto itr: dictionary)
        {
            if(isPresent(itr, board))
                ans.push_back(itr);
        }
        
        return ans;
    }