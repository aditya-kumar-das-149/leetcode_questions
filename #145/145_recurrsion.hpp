/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postorder(TreeNode* n , vector<int> &v){
        if(n==NULL)return;
        postorder(n->left,v);
        postorder(n->right,v);
        v.push_back(n->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorder(root,v);
        return v;
        
    }
};