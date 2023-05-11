int get_sum(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int sum = root -> data;
    sum = get_sum(root -> left) + get_sum(root -> right);
    return sum;
}