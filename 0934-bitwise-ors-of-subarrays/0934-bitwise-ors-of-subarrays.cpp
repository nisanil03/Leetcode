

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        std::unordered_set<int> result_ors;
        std::unordered_set<int> current_ors;
        for(int x : arr){
            std::unordered_set<int>next_ors;
            next_ors.insert(x);
            for(int y : current_ors){
                next_ors.insert(x | y);
            }
            result_ors.insert(next_ors.begin(), next_ors.end());

            current_ors = next_ors;
        }
        return result_ors.size();
    }
};