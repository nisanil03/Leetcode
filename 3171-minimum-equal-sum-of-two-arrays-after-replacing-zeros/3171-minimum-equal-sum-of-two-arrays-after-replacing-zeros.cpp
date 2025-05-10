class Solution {
public:
    static long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=reduce(nums1.begin(), nums1.end(), 0LL),
            sum2=reduce(nums2.begin(), nums2.end(), 0LL);
        int zero1=count(nums1.begin(), nums1.end(), 0), 
            zero2=count(nums2.begin(), nums2.end(), 0);
        if ((zero1==0 && sum1<sum2+zero2)||(zero2==0 && sum2<sum1+zero1))
            return -1;
        return max(sum1+zero1, sum2+zero2);
    }
};