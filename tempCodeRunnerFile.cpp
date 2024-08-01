int maxHeight(TreeNode* root){
    if(root==NULL) return 0;

    int lh = maxHeight(root->left);
    if(lh==-1) return -1;

    int rh = maxHeight(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1 + max(lh,rh);
}