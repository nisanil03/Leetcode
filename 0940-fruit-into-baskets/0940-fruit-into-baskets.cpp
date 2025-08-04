class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int s = 0, maxLen = 0;
        unordered_map<int ,int> basket;

        for(int end = 0; end < fruits.size(); ++end){
            basket[fruits[end]]++;

            while(basket.size() > 2){
                basket[fruits[s]]--;
                if(basket[fruits[s]] == 0){
                    basket.erase(fruits[s]);
                }
                s++;
            }
            maxLen = max(maxLen , end - s + 1);
        }
        return maxLen;
    }
};