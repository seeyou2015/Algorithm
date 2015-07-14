// Simple recursive solution.
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root ||p==q)
            return p;
        if(q==root)
            return q;
        if(root== NULL)
            return NULL;
        TreeNode*left =  lowestCommonAncestor(root->left, p ,q);
        TreeNode*right = lowestCommonAncestor(root->right, p ,q);
        if(left ==NULL)
            return right;
        if(right ==NULL)
            return left;
        if(left!=NULL && right !=NULL)
            return root;
    }
    
};
