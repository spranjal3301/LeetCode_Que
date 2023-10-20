class Solution {
    bool isSafe(vector<string> board,int row,int col,int n){
        int i=row;
        int j=col;

        while(j>=0){
            if(board[row][j]=='Q')return false;
            j--;
        }
        j=col;
        while(j>=0 and i<n){
            if(board[i][j]=='Q')return false;
            j--;
            i++;
        }
        i=row;
        j=col;
        while(j>=0 and i>=0){
            if(board[i][j]=='Q')return false;
            j--;
            i--;
        }
        return true;
    }
    void totalNQueens(vector<string>& board,int n,int& count,int col) {
        if(col==n){
            count++;
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                totalNQueens(board,n,count,col+1);
                board[row][col]='.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        int count=0;
        int col=0;
        totalNQueens(board,n,count,col);
        return count;  
    }
};