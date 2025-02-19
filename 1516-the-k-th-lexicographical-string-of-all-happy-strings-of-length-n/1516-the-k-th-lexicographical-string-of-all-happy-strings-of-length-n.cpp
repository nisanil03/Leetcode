
class Solution {
public:
    string getHappyString(int n, int k) {
       queue<string> q;
       q.push("a");
       q.push("b");
       q.push("c");
       vector<string> happyString;

       while(!q.empty()){
        string s = q.front();
        q.pop();
        if(s.size() == n){
            happyString.push_back(s);
            continue;
        }
        for(char ch : {'a' , 'b' , 'c'}){
            if(s.back() != ch){
                q.push(s + ch);
            }
        }
       } 
       return k > happyString.size() ? "" : happyString[k -1];
    }
};