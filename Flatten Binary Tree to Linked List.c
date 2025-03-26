class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr!=NULL) {
            if(curr->left!=NULL) {
                // save the right subTree
                TreeNode* r = curr->right;
                curr->right = curr->left;
                // finding predecessor
                TreeNode* pred= curr->left;
                while(pred->right!=NULL) pred = pred->right;
                // Linking predecessor to the right subTree
                pred->right = r;
                curr = curr->left;
            }
            else curr = curr->right;
        }
        TreeNode* temp = root;
        while(temp!=NULL) { // Making the left node NULL 
            temp->left = NULL;
            temp = temp->right;
        }
    }
};
