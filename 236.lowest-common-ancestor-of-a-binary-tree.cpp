/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool first = false;
        TreeNode* result;
        result = searchCommonAncestor(root, p, q);
        return result;
    }

    TreeNode* searchCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool first){
        TreeNode* ltmp;
        TreeNode* rtmp;
        TreeNode* tmp = nullptr;
        if(root == nullptr)
            return nullptr;
        ltmp = searchCommonAncestor(root->left, p, q);
        rtmp = searchCommonAncestor(root->right, p, q);
        if(ltmp)
            tmp = ltmp;
        if(rtmp)
            tmp = rtmp;
        if(ltmp != nullptr & rtmp != nullptr){
            tmp = root;
            }
        if(root == p || root == q){
            tmp = root;}
        if((ltmp != nullptr || rtmp != nullptr) & (root == p || root == q)){
            tmp = root;
            }
        return tmp;
    }
};