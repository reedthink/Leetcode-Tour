//https://leetcode-cn.com/problems/surface-area-of-3d-shapes/
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid)
    {
        //计算所有的表面积，减去接触的面积

        int  total_S=0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                total_S += grid[i][j]*6;
                if(grid[i][j])
                total_S -= (grid[i][j]-1)*2;
                // printf("%d %d:%d ",i,j,grid[i][j]);
                // cout<<total_S<<endl;
            }
        }
        //计算总接触面积
        int touch00 = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i > 0) {
                    touch00 += min(grid[i - 1][j], grid[i][j]);
                }
                if (i < grid.size() - 1)
                    touch00 += min(grid[i + 1][j], grid[i][j]);
                if (j > 0)
                    touch00 += min(grid[i][j - 1], grid[i][j]);
                if (j < grid[i].size()-1)
                    touch00 += min(grid[i][j + 1], grid[i][j]);
            }
        }
        // touch00 = 2;
        return total_S - touch00;
        // return total_S;
        // return touch00;


    }
};