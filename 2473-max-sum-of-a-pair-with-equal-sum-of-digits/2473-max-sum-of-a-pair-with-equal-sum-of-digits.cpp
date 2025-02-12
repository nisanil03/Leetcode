class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int mp[82];
        memset(mp , -1 , sizeof(mp));
        int ans = -1;

        for(int num : nums){
            int sum = 0, temp = num;
            while(temp)  sum += temp % 10, temp /= 10;

            if(mp[sum] != -1)
              ans = max(ans, num + mp[sum]);

              mp[sum] = max(mp[sum],num);
        }
        return ans;
    }
};