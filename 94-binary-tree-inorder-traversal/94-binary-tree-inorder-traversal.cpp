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
    // vector<int> roots;
    vector<int> inorderTraversal(TreeNode* root){
         vector<int> roots;
        if(root==NULL){
            return {};
        }
        vector<int> v1 = inorderTraversal(root->left);
        for(auto i:v1) roots.push_back(i);
        roots.push_back(root->val);
       vector<int> v2 =  inorderTraversal(root->right);
        for(auto i:v2) roots.push_back(i);
        return roots;
    }
};