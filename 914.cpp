//easy
class Solution {
public:
    int gcd(int a,int b)
    {
        int r;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> mp;
        for(auto it = deck.begin();it!=deck.end();it++)
        {
            mp[*it]++;
        }
        auto it=mp.begin();
        int zan= it->second;

        it++;
        for(;it!=mp.end();it++)
        {
            zan=gcd(zan,it->second);
        }
        if(zan<2)
            return false;
        return true;
    }
};