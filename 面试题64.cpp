//面试题64.cpp
// https://leetcode-cn.com/problems/qiu-12n-lcof/
class Solution {
public:
    int sumNums(int n) {
        // int ans=0;/  
        n&&(n=sumNums(n-1)+n);
        return n;
    }
};