class Solution {
public:
    int numberOfSubstrings(string s) {
       int abc[3] = {-1 , -1, -1};
       int count = 0 , right = 0;
       while(right < s.length()){
        abc[s[right] - 'a'] = right;
        int minIndex = INT_MAX;
        for(int i = 0; i < 3; i++){
            minIndex = min(minIndex , abc[i]);
        }
        count += (minIndex + 1);
        right++;
       } 
       return count;
    }
};