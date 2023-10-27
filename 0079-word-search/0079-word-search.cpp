class Solution {
    bool isPathPossible(int newx,int newy,vector<vector<char>> &matrix,vector<vector<bool>>& visited,string& word,int i){
     int n=matrix.size();
    int m=matrix[0].size();   
    if ((newx>=0 and newx<n) and (newy>=0 and newy<m) and visited[newx][newy]==0 and matrix[newx][newy]==word[i])
    {
        return true;
    }
    else{
        return false;
    }
        
}
    void solve(vector<vector<char>>& board, vector<vector<bool>>& visited,string& word,int x,int y,int i,bool& ans){
        if(i>=word.size()){
            ans=true;
            return;
        }
        visited[x][y]=1;

        if(!ans && isPathPossible(x+1,y,board,visited,word,i)){
            solve(board,visited,word,x+1,y,i+1,ans);
        }
        if(!ans && isPathPossible(x-1,y,board,visited,word,i)){
            solve(board,visited,word,x-1,y,i+1,ans);
        }
        if(!ans && isPathPossible(x,y+1,board,visited,word,i)){
            solve(board,visited,word,x,y+1,i+1,ans);
        }
        if(!ans && isPathPossible(x,y-1,board,visited,word,i)){
            solve(board,visited,word,x,y-1,i+1,ans);
        }

        //!Backtrack
         visited[x][y]=0;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    bool ans=false;
                    int idx=1;
                    solve(board,visited,word,i,j,idx,ans);
                    if(ans)return true;
                }
            }
        }
        return false;
    }
};