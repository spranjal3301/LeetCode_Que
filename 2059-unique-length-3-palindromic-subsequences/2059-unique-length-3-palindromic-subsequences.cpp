class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> freq;
        unordered_map<char, pair<int, int>> mp;
        int uni = 0;

        vector<int> temp(26, 0);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (mp.find(c) != mp.end()) {
                mp[c] = {mp[c].first, i};
            } else {
                uni++;
                mp[c] = {i, i};
            }
            temp[c - 'a']++;
            freq.push_back(temp);
        }

        int res = 0;
        for (auto [f, se] : mp) {
            if (se.second - se.first <= 1)
                continue;
            int e = se.second;
            int st = se.first;

            // cout<<st<<" "<<e<<endl;
            // int cnt = 0;
            freq[e][f-'a']--;
            for (int i = 0; i < 26; i++) {
                // cout << (freq[e][0]) << endl;
                res += ((freq[e][i] - freq[st][i])> 0);
            }
            freq[e][f-'a']++;
        }


        return res;
    }
};
// a a b c a
// 1 1 2 3 3

// a b a c a b
// 1 2 2 3 3 3