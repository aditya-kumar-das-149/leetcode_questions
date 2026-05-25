#include<vector>
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
    vector<int> preorder(TreeNode* n,vector<int> &v){
        if(n==NULL){
            v.push_back(98123);
            return v;
        }
        v.push_back(n->val);
        preorder(n->left,v);
        preorder(n->right,v);
        return v;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        if(p==NULL || q==NULL)return false;
        vector<int> v,u;
        preorder(p,v); 
        preorder(q,u);
        int a=v.size(),b=u.size();
        while(a>=0&& b>=0){
            if(v[a]==u[b]){
                a--;
                b--;
            }else{
                return false;
            }
        } 
        if(a==-1 && b==-1){
            return true;
        }
        return false;
    }
};