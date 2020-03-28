//反转所有字符串，然后排序，之后判断word[i-1]是不是word[i]的前缀，如果不是，word[i-1]必须加入索引字符串列表
class Solution {
public:
    int pd1(string b, string a)
    {
        int i = 0;
        int j = 0;
        while (j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                return 0;
            }
        }
        return 1;
    }
    int minimumLengthEncoding(vector<string>& words)
    {
        for (int i = 0; i < words.size(); i++) {
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(), words.end());
        words.push_back("*");
        int ans = 0;
        for (int i = 1; i < words.size(); i++) {
            if (pd1(words[i - 1], words[i]) == 0) {
                ans += words[i - 1].size() + 1;
            }
        }
        return ans;
    }
};