class Solution {
public:

    TreeNode* postion(TreeNode* root,int key){
        while(root != NULL){
            if(root->val == key)return root;
            if(root->val < key)
                root = root->right;
            else
                root = root->left;
        }
        return NULL;
    }
    int choice(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL)return 1;
        if((root->left && root->right == NULL) || (root->left == NULL && root->right))return 2;
        return 3;
    }
    int inorder_sucessor(TreeNode* root){
        while(root->left != NULL){
            root = root->left;
        }
        return root->val;
    }
void delete_sucessor(TreeNode* &root, int key){
    if(root == NULL)return;
    if(root->val == key){
        TreeNode* temp = root;
        if(root->right)
            root = root->right;
        else
            root = NULL;
        delete temp;
        return;
    }
    TreeNode* cur = root;
    while(cur->left && cur->left->val != key){
        cur = cur->left;
    }
    if(cur->left == NULL) return;
    TreeNode* temp = cur->left;
    cur->left = temp->right;
    delete temp;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return root;
        if(key < root->val){
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(key > root->val){
            root->right = deleteNode(root->right, key);
            return root;
        }
        switch(choice(root)){
            case 1:
                delete root;
                return NULL;
            case 2:
                if(root->left){
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                else{
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
            case 3:
                int value = inorder_sucessor(root->right);
                root->val = value;
                delete_sucessor(root->right, value);
                return root;
        }
        return root;
    }
};