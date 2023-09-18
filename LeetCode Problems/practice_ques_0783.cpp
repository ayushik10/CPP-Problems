/*  783.  MINIMUM DISTANCE BETWEEN BST NODES

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:
The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
 */


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
    void solve(TreeNode* root, int &prev, int &minDiff) {
        if(root==NULL)
        return;
        
        solve(root->left, prev, minDiff);

        if(prev != -1)
        minDiff = min(minDiff, root->val-prev);

        prev = root->val;

        solve(root->right, prev, minDiff);

    }

    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;

        solve(root, prev, minDiff);

        return minDiff;
    }
};
