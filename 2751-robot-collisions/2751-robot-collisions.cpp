class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
     int n = positions.size();
     vector<int> indices(n) , result;
     stack<int> stack;

     for(int index =0; index < n; ++index){
        indices[index] = index;
     }   
     sort(indices.begin(),indices.end(),
     [&](int lhs , int rhs) {return positions[lhs] < positions[rhs]; });

     for(int currentIndex : indices){
        if(directions[currentIndex] == 'R'){
            stack.push(currentIndex);
        }
        else{
            while(!stack.empty() && healths[currentIndex] > 0){
                //pop the top robot form the stack for collision check
                int topIndex = stack.top();
                stack.pop();

                //Top robot survies, currnet robot is destroyed
                if(healths[topIndex] > healths[currentIndex]){
                    healths[topIndex] -= 1;
                    healths[currentIndex] = 0;
                    stack.push(topIndex);
                }
                else if(healths[topIndex] < healths[currentIndex]){
                    //current robot surrvives , top robot is destroyed
                    healths[currentIndex] -= 1;
                    healths[topIndex] = 0;
                }
                else{
                    //both robots are destroyed
                    healths[currentIndex] = 0;
                    healths[topIndex] = 0;
                }
            }
        }
     }
     //collect surviving robots
     for(int index = 0; index < n; ++index){
        if(healths[index] > 0){
            result.push_back(healths[index]);
        }
     }
     return result;
    }
};