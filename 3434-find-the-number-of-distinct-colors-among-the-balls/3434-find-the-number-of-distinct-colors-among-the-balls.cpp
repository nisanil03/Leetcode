class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int , set<int>> mpp;
        map<int , int> mp;
        vector<int>ans;
        for(auto it : queries){
            int color = it[1];
            int ball = it[0];

            if(mp.find(ball) == mp.end()){
                mp[ball] = color;
                mpp[color].insert(ball);
            }
            else{
                int c = mp[ball];
                mpp[c].erase(ball);
                if(mpp[c].empty()){
                    mpp.erase(c);
                }
                mp[ball] = color;
                mpp[color].insert(ball);
            }
            ans.push_back(mpp.size());
        }
        return ans;
    }
};