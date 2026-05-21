class Solution {
public:
    struct Node {
        Node* child[10];
        bool isEnd;
        Node(){
            for(int i=0;i<10;i++)child[i]=nullptr;
            isEnd=false;
        }
    };
    void insert(string word, Node* root){
        Node* temp=root;
        for(char ch:word){
            int idx=ch-'0';
            if (temp->child[idx] == nullptr){
                temp->child[idx] = new Node();
            }
            temp=temp->child[idx];
        }
        temp->isEnd=true;
    }

    int check(string str, Node* root) {
        Node* temp = root;
        int idx = 0;
        while (idx < str.size()) {
            int i = str[idx] - '0';
            if (temp->child[i] != nullptr) {
                temp = temp->child[i];
                idx++;
            } else {
                break;
            }
        }
        return idx;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node* root = new Node();
        for(int x:arr2){
            string str=to_string(x);
            insert(str,root);
        }
        int ans=0;
        for(int x:arr1){
            string str=to_string(x);
            ans=max(ans,check(str, root));
        }
        return ans;
    }
};