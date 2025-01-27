class Solution {
    vector<vector<int>> grph;
    vector<int> ind;
    unordered_map<int,unordered_map<int,bool>> isPre;
    void topoSort(int nc) {
        // vector<int> ts;
        queue<int> q;

        for (int i = 0; i < nc; i++) {
            if (ind[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            // ts.push_back(node);

            for (auto u : grph[node]) {
                isPre[u][node] = true;
                for(auto [f,s]:isPre[node]){
                    if(s)isPre[u][f] = true;
                }
                
                ind[u]--;
                if (ind[u] == 0)
                    q.push(u);
            }
        }

        // return ts;
    }

public:
    vector<bool> checkIfPrerequisite(int nc, vector<vector<int>>& preq,
                                     vector<vector<int>>& qur) {
        if(preq.size()== 0)return vector<bool>(qur.size(),0);
        grph = vector<vector<int>>(nc);
        ind = vector<int>(nc, 0);
        for (auto ed : preq) {
            grph[ed[0]].push_back(ed[1]);
            ind[ed[1]]++;
        }

        topoSort(nc);

        unordered_map<int,vector<pair<int,int>>> mp;

        for(int i=0;i<qur.size();i++){
            mp[qur[i][1]].push_back({qur[i][0],i});
        }

        vector<bool> res;

        for(auto q:qur){
            if(isPre[q[1]][q[0]])
                res.push_back(true);
            else 
                res.push_back(false);

        }
        

        return res;
    }
};

// wrt topo_sort
// 1 2 0

// map : v : {u,j},u1 ... un
