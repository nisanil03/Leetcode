class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size()-2;
        bitset<100> seen=0;
        vector<int> ans;
        for(int x: nums){
            if (seen[x]) ans.push_back(x);
            else seen[x]=1;
        }
        return ans;
    }
};