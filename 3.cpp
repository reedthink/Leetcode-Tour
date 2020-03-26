class Solution {
public:
    // 尺取
    int lengthOfLongestSubstring(string s) {
        int letter_num[260]={};
        int ans=1;
        int i=0 ,j=0,f=1;
        int n=s.size();
        if(n)
        {
            s.push_back(s[n-1]);
            n++;
        }
        while(i<n&&j<n)
        {
            letter_num[s[j]]++;
            if(letter_num[s[j]]!=1)
            {    
                ans=max(ans,j-i);
                while(letter_num[s[j]]!=1)
                {
                   letter_num[s[i]]--;
                   i++;
                }

                f=0;
            }
            j++;
        }
        
        return ans;
    }
};