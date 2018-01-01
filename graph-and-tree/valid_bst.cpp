bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (root->left == nullptr || root->right == nullptr)
            return true;
        else if (root->val > root->left->val && root->val < root->right->val){
            return (isValidBST(root->left) && isValidBST(root->right));
        }
        else{
            return false;
        }
    }