class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
      unordered_map<string , int> count;

      for(const auto& row : matrix){
        string key;
        bool flip = row[0] == 1;

        for(int num : row){
            key += flip ? ('0' + (1 - num)) : ('0' + num);
        }
        count[key]++;
      }  
      int maxcount = 0;
      for(const auto& pair : count){
        maxcount = max(maxcount , pair.second);
      }
      return maxcount;
    }
};