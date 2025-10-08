class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(auto spell :spells){
            long key = (success + spell -1)/spell;
            auto low = lower_bound(potions.begin(),potions.end(),key);
            ans.push_back(potions.end()-low);
        }
        return ans;
    }
};