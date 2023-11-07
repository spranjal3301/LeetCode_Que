class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<float> time(n,0);
        for(int i=0;i<n;i++){
            time[i]=dist[i]/(float)speed[i];
        }
        sort(time.begin(),time.end());

        for(int i=1;i<n;i++){

            if(time[i]<=(float)i)return i;
        }
        return n;
    }
};