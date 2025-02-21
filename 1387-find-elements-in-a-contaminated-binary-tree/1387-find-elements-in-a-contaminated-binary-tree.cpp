
class FindElements {
    private:
    unordered_set<int> values;

    void recoverTree(TreeNode* root , int value){
        if(!root) return;
        root->val = value;
        values.insert(value);
        recoverTree(root->left , 2 * value + 1);
        recoverTree(root->right , 2 * value + 2);
    }
public:
    FindElements(TreeNode* root) {
        recoverTree(root , 0);
    }
    
    bool find(int target) {
        return values.count(target);
    }
};

