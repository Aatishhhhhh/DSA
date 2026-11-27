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
    int maxDepth(TreeNode* root) {
        int basecount = 1;
        // base case return when no children present
        if(root == NULL){
            return 0;
        }
        // left side sapn
        int ldept = basecount + maxDepth(root -> left);
        // right side span
        int rdept = basecount + maxDepth(root -> right);
        if(ldept == rdept ){
            return ldept;
        }
        else if(ldept > rdept){
            return ldept;
        }
        else{
            return rdept;
        } 
    }
};