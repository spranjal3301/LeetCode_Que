class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> matrix(n, vector<int>(n, 0));
    int element = 1;
    int first_row = 0;
    int last_col = n - 1;
    int last_row = n - 1;
    int first_col = 0;

    while (element <= n * n)
    {
        for (int i = first_row; i <= last_col and element <= n * n; i++)
        {
            
            matrix[first_row][i] = element;
            element++;
        }
        first_row++;

        for (int i = first_row; i <= last_row and element <= n * n; i++)
        {
            
            matrix[i][last_col] = element;
            element++;
        }
        last_col--;

        for (int i = last_col; i >= first_col and element <= n * n; i--)
        {
            matrix[last_row][i] = element;
            element++;
        }
        last_row--;

        for (int i = last_row; i >= first_row and element <= n * n; i--)
        {
            matrix[i][first_col] = element;
            element++;
        }
        first_col++;
    }
    return matrix;
    }
};