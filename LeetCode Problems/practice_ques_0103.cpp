/*  103.  BINARY TREE ZIGZAG LEVEL ORDER TRAVERSAL.

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        
        if(root == NULL)
        return answer;
        
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = false;

        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);

            for(int i=0; i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                int index = (leftToRight) ?(size-(i+1)):i; 
                ans[index] = frontNode->val;

                if(frontNode->left != NULL)
                q.push(frontNode->left);

                if(frontNode->right != NULL)
                q.push(frontNode->right);
            }
            leftToRight = (leftToRight)? false:true; //to change direction
                answer.push_back(ans);
        }
        return answer;
    }
};
