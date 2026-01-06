class Solution {
public:
    vector<int> sum={INT_MIN};
    void dfs(TreeNode* Node, int level=1){
        if (Node==NULL) return;
        if (sum.size()==level) sum.push_back(Node->val);
        else sum[level]+=Node->val;
        dfs(Node->left, level+1);
        dfs(Node->right, level+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root);
        return max_element(sum.begin(), sum.end())-sum.begin();
        
    }
};