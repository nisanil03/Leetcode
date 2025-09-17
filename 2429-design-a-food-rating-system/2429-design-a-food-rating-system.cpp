class FoodRatings {
public:
struct cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
    if (a.first == b.first)return a.second > b.second;return a.first < b.first;
    }
};
unordered_map<string,set<pair<int,string>,cmp>> m;
unordered_map<string,int> m2;unordered_map<string,string> m3;

    FoodRatings(vector<string>& foods, vector<string>& c, vector<int>& r)
    {    int n = foods.size();
        for(int i=0;i<n;i++){
            m[c[i]].insert({r[i],foods[i]});
            m2[foods[i]]=r[i];m3[foods[i]]=c[i];
        }
    }
    
    void changeRating(string food, int n) {
        auto it = m[m3[food]].find({m2[food],food});
        if(it!=m[m3[food]].end()){m[m3[food]].erase(it);}
        m[m3[food]].insert({n,food});m2[food]= n;
    }
    
    string highestRated(string c) {
        auto it = m[c].rbegin();
        return (*it).second;
    }
};