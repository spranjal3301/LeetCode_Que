class Solution
{
    bool isSafePlace(vector<string> board, int n, int row, int col)
    {

        for (int j = col; j >= 0; j--)
        {
            if (board[row][j] == 'Q')
                return false;
        }
        //! No need to check boz we are only placeing one Queen in one col
        int i = row;
        int j = col;

        while (i >= 0 and j >= 0)
        {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = row;
        j = col;
        while (i < n and j >= 0)
        {
            if (board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solveNQueens(int n, vector<vector<string>> &ans, vector<string>& board, int col)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafePlace(board, n, row, col))
            {
                board[row][col] = 'Q';
                solveNQueens(n, ans, board, col + 1);
                //! backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        int col = 0;
        solveNQueens(n, ans, board, col);

        return ans;
    }
};