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
    int goodNodes(TreeNode* root,int maz=INT_MIN) {
        if(root==NULL)
        return 0;
        int count =0;
        if(maz<=root->val)
        {
            maz = root->val;
            count+=1;
        }   
        return count+=goodNodes(root->right,maz)+goodNodes(root->left,maz);
    }
};