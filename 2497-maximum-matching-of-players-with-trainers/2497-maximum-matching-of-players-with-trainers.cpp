class Solution {
public:
    int matchPlayersAndTrainers(std::vector<int>& players,std:: vector<int>& trainers) {
        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());

        int count = 0;
        int i = 0 , j = 0;

        while(i < players.size() && j < trainers.size()){
            if(players[i] <= trainers[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};