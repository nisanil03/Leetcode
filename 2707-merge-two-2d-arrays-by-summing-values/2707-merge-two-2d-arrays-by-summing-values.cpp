class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0 , j = 0;
        vector<vector<int>>result;

        while(i < nums1.size() && j < nums2.size()){
            int id1 = nums1[i][0] , val1 = nums1[i][1];
            int id2 = nums2[j][0] , val2 = nums2[j][1];

            if(id1 < id2){
                result.push_back({id1 , val1});
                i++;
            }
            else if ( id2 < id1){
                result.push_back({id2 , val2});
                j++;
            }
            else{
                result.push_back({id1 , val1 + val2});
                i++;
                j++;
            }
        }
        while(i < nums1.size()){
            result.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            result.push_back(nums2[j]);
            j++;
        }
        return result;
    }
};