class Solution {
public:
   bool SolveUsingRecursion(int index , vector<int> & nums , int target){
    // base case 
    int n = nums.size();
   if(index >= n)
      return 0;

    if(target < 0)
       return 0;

    if(target == 0)
      return 1 ;     

    // include 
    bool include = SolveUsingRecursion(index + 1 , nums , target - nums[index]);
    //exclude 
    bool exclude = SolveUsingRecursion(index +1 , nums , target);

    // return answer 
    return (include || exclude);
   }

// top down approach 
bool solveUsingMem(int index , vector<int> & nums , int target , vector<vector<int>> & dp){
    // base case 
    int n = nums.size();
    if(index >= n)
       return 0;

    if(target < 0)
       return 0;

    if(target == 0)
      return 1;

      // step 3 answer are allready exist or not 
      if(dp[index][target] != -1)
          return dp[index][target];

    //include 
    bool include = solveUsingMem(index +1 , nums , target - nums[index] , dp);

    //exclude 
    bool exclude = solveUsingMem(index + 1 , nums, target , dp);

    // step 2 
   dp[index][target] = (include || exclude);
   //return ans 
   return dp[index][target];
}
// bottom up approach 
bool SolveUsingTabulation(vector<int>& nums , int target){
    int n = nums. size();
    vector<vector<int>> dp(n + 1, vector<int>(target +1 , 0));
     for(int i = 0; i <nums.size() ; i++){
        dp[i][0] = 1;
     }
     for(int index = n- 1 ; index >= 0 ; index--){
        for(int t = 1; t <= target ; t++){
            // include 
            bool include = 0;
            if(t - nums[index] >= 0)
            include =  dp[index + 1] [t - nums[index]];

            //exclude 
            bool exclude = dp[index +1] [t];
            
            // return answer
            dp[index][t] = (include || exclude);
            
        }
     }
    return dp[0][target];
}   
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        // yea hi galti hogi 
        if(sum & 1)
           return false;

        int target = sum/ 2;
        int index = 0;
        //bool ans = SolveUsingRecursion(index , nums , target);

        // top down approach 
        //step 1 create 2 D dp array
        //  vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        //  bool ans = solveUsingMem(index ,nums , target , dp);
        // bottom up approach :
        bool ans = SolveUsingTabulation(nums , target);
        return ans;
    }
};