class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n = nums.size()-1;
        int s=0;
        int e=n;
        int mid ;
        while(s<e){
            mid = s+(e-s)/2;
            if(nums[mid]>nums[e])
            {
                s=mid+1;
            }
            else if (nums[mid] < nums[e])
            {
                e = mid;
            }
            else 
            e--;
        }
        return nums[s];
    }
};