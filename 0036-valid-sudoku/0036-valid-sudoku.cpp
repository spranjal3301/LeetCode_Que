class Solution {
     bool isValid(vector<vector<char>> &board,int row,int n){
         int col=row;
        unordered_map<char,int> um;
        for (int j = 0; j <n; j++)
        {
            char digit=board[row][j];
            if(digit!='.')um[digit]++;
            if(um[digit]>1)return false;
        }
        um.clear();
        for (int j = 0; j <n; j++)
        {
            char digit=board[j][row];
            if(digit!='.')um[digit]++;
            if(um[digit]>1)return false;
        }
        return true;
    }
bool isValidGrid(vector<vector<char>> &board,int n){
    for(int i=0;i<9;i+=3){
        
        for(int j=0;j<9;j+=3){
            unordered_map<char,int> um;
            for(int k=0;k<9;k++){
                    char digit=board[3*(i/3)+k/3][3*(j/3)+k%3];
                    if(digit!='.')um[digit]++;
                    if(um[digit]>1)return false;

            }
            
        }
    }
    return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        
        for(int row=0;row<9;row++){
            if(!isValid(board,row,n))return false;
        }
        if(!isValidGrid(board,n))return false;
        
        return true;
    }
};