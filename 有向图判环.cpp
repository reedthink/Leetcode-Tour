#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//https://leetcode-cn.com/problems/course-schedule/
class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
    void dfs(int u)
    {
        visited[u] = 1;
        for (int v : edges[u])
        {
            if (visited[v]==0)//未访问过
            {
                dfs(v);
                if (!valid)
                {
                    return;
                }
            }
            else if (visited[v] == 1)//访问中
            {
                valid = false;
                return;
            }
        }
        visited[u] = 2;//入栈
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]); //0指向1
        }
        for (int i = 0; i < numCourses && valid; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        return valid;
    }
};
int main()
{

    return 0;
}
