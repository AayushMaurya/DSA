// Detect Capital

#include <bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word) {
        if(word[0] >= 'A' && word[0] <= 'Z')
        {
            int upperCount = 0, lowerCount = 0;
            for(int i=1; i<word.size(); i++)
            {
                if(word[i] >= 'A' && word[i] <= 'Z')
                    upperCount++;
                else
                    lowerCount++;
            }
            if(upperCount == word.size()-1 || lowerCount == word.size()-1)
                return true;
            else 
                return false;
        }
        else{
            for(int i=0; i<word.size(); i++)
            {
                if(word[i] >= 'A' && word[i] <= 'Z')
                    return false;
            }
        }

        return true;
    }