class Solution {
public:
 class range{
public:
    int row;
    int col;
    int val;
    range(int row,int col,int val):row(row),col(col),val(val){}
};
class myComp{
public:
    bool operator()(range* a,range* b){
        return a->val>b->val;
    }
};
vector<int> smallestRange(vector<vector<int>> &nums)
{
    priority_queue<range*,vector<range*>,myComp> mipq;
    priority_queue<int> mxpq;

    for (int i = 0; i < nums.size(); i++)
    {
        range *temp=new range(i,0,nums[i][0]);
        mipq.push(temp);
        mxpq.push(nums[i][0]);
    }
    //range {a,b} (b>a)
    int a=mipq.top()->val;
    int b=mxpq.top();

    while (mipq.size()>1)
    {
        range *mini=mipq.top();
        mipq.pop();
        int p=mini->val;
        int q=mxpq.top();
        // mxpq.pop();
        cout<<p<<"-"<<q<<" ";
        if((q-p)<(b-a)){
            a=p;
            b=q;
        }
        int i=mini->row;
        int j=mini->col;
        if(j+1<nums[i].size()){
            mxpq.push(nums[i][j+1]);
            range *next=new range(i,j+1,nums[i][j+1]);
            mipq.push(next);
        }
        else break;
    }
    
    return {a,b};


}
};