class Solution {
    int dijkstra(vector<vector<pair<int,int>>>&  gph,int n,int s=0){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dist(n,INT_MAX);

        pq.push({s,0});
        dist[s]=0;

        while(!pq.empty()){
            int u=pq.top().first;
            int cw=pq.top().second;
            pq.pop();
            if(u == n - 1) return dist[n-1];
             if(cw > dist[u]) continue;
            for(auto [v,wt]:gph[u]){
                if(dist[v]>cw+wt){
                    pq.push({v,cw+wt});
                    dist[v]=cw+wt;
                } 
            }
        }

        return dist[n-1];

    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> grph(n);// u:{v,weight} 

        for(int i=0;i<n-1;i++){
            grph[i].push_back({i+1,1});
            // grph[i+1].push_back({i,1});
        }


        int k=queries.size();
        vector<int> ans(k,n-1);
        for(int i=0;i<k;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            grph[u].push_back({v,1});
            // grph[v].push_back({u,1});
            ans[i]=dijkstra(grph,n);

        }

        return ans;

    }
};