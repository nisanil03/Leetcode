class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto& op : operations)
        x += 44 - op[1];
        return x;
    }
};