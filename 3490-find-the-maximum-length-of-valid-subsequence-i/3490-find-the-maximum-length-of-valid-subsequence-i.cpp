class Solution {
public:
    int maximumLength(vector<int>& nums) {
       int even = 0 , odd = 0;
       for(int num : nums){
        if(num % 2 == 0) even++;
        else odd++;
       } 
       int even_dp = 0, odd_dp = 0;
       for(int num : nums){
        if(num % 2 == 0)
         even_dp = max(even_dp , odd_dp + 1);
         else
          odd_dp = max(odd_dp , even_dp + 1);
       }
       return max({even , odd , even_dp, odd_dp});
    }
};