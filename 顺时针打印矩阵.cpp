class Solution
{
public:
    int n, m;
    vector<int> v;
    void print(vector<vector<int>> &mat, int x, int y)
    {
        for (int i = y; i < m; i++)
        {
            v.push_back(mat[x][i]);
        }
        for (int i = x + 1; i < n; i++)
        {
            v.push_back(mat[i][m - 1]);
        }

        if (n - 1 != x)
            for (int i = m - 2; i >= y; i--)
            {
                v.push_back(mat[n - 1][i]);
            }
        if (m - 1 != y)

            for (int i = n - 2; i > x; i--)
            {
                v.push_back(mat[i][y]);
            }
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        if (n)
            m = matrix[0].size();
        int x, y;
        x = 0, y = 0;
        while (x < n && y < m)
        {
            print(matrix, x, y);
            x++;
            y++;
            n--;
            m--;
        }
        return v;
    }
};