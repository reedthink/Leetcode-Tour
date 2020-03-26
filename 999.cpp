//没啥好说的，确定位置，然后向四个方向进行测试
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board)
    {
        int row, col;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'R') {
                    row = i;
                    col = j;
                }
            }
        }
        int ans = 0;
        int i = col - 1;
        while (i >= 0) {
            if (board[row][i] == 'B') {
                break;
            }
            if (board[row][i] == 'p') {
                ans++;
                break;
            }
            i--;
        }
        i = col + 1;
        while (i < 8) {
            if (board[row][i] == 'B') {
                break;
            }
            if (board[row][i] == 'p') {
                ans++;
                break;
            }
            i++;
        }
        i = row - 1;
        while (i >= 0) {
            if (board[i][col] == 'B') {
                break;
            }
            if (board[i][col] == 'p') {
                ans++;
                break;
            }
            i--;
        }
        i = row + 1;
        while (i < 8) {
            if (board[i][col] == 'B') {
                break;
            }
            if (board[i][col] == 'p') {
                ans++;
                break;
            }
            i++;
        }
        return ans;
    }
};
/* 
[[".",".",".",".",".",".",".","."],
 [".",".",".","p",".",".",".","."],
 [".",".",".","p",".",".",".","."],
 ["p","p",".","R",".","p","B","."],
 [".",".",".",".",".",".",".","."],
 [".",".",".","B",".",".",".","."],
 [".",".",".","p",".",".",".","."],
 [".",".",".",".",".",".",".","."]]

 */