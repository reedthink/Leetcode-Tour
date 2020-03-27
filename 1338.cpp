/* 
将数字按照出现的次数进行排序，贪心即可
 */
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(auto it=arr.begin();it!=arr.end();it++)
        {
            mp[*it]++;
        }
        priority_queue<int> pq;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            pq.push(it->second);
        }
        int sz=arr.size(),ans=0,n;
        n=0;
        while(!pq.empty()&&ans*2<sz)
        {   
            ans+=pq.top();
            pq.pop();
            n++;
        }
        return n;
    }
};
