
class Solution {
public:
int i =0;
    TreeNode* recoverFromPreorder(string t , int depth=0) {
        if(i>=t.size()) return NULL;
        int d=0;

        while(t[i]  == '-') d++ , i++;

        if(d < depth){
            i-=d;
            return NULL;
        }
        int x = 0;
        while(isdigit(t[i])){
            x=x*10 + t[i] -'0';
            i++;
        }
            TreeNode* node = new TreeNode(x);

            node->left=recoverFromPreorder(t, depth+1);
            node->right=recoverFromPreorder(t, depth+1);

            return node;
        
    }
};