/*  104. MAXIMUM DEPTH OF BINARY TREE

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2
 

Constraints:
The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100         */




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

    void solve(int &depth, TreeNode* root, int cnt) {

        if(root==NULL) {
            depth = max(depth, cnt);
            return;
        }

        solve(depth, root->left, cnt+1);
        solve(depth, root->right, cnt+1);
    }

    int maxDepth(TreeNode* root) {

        int depth = 0;
        solve(depth, root, 0);

        return depth;
    }
};
