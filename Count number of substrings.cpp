class Solution
{
  public:
    long long int substCount (string s, int k) {
        vector<int> charCount(26, 0);
        int distinct = 0;
        int left = 0;
        long long int ans = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            int index = s[i]-'a';
            
            charCount[index]++;
            if(charCount[index]==1)
                distinct++;
            
            while(distinct > k)
            {
                int leftIndex = s[left]-'a';
                charCount[leftIndex]--;
                if(charCount[leftIndex]==0)
                    distinct--;
                left++;
            }
            ans += i-left+1;
        }
        return ans;
    }
    long long int substrCount (string s, int k){
        return substCount(s, k) - substCount(s, k-1);
    }
};
