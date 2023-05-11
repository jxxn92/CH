void node_plus_one(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    node_plus_one(root -> left);
    root -> data++;
    node_plus_one(root -> right);
    root -> data++;
}