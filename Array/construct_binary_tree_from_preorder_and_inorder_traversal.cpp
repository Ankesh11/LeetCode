//Problem : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* build_tree_util(vector<int>& preorder, vector<int>& inorder, int &n, int index, int beg, int end){
        if(beg>end || index>=n){
            return NULL;
        }
        
        int pos;
        for(int i=beg;i<=end;i++){
            if(inorder[i]==preorder[index]){
                pos = i;
                break;
            }
        }
        
        TreeNode* node = new TreeNode(inorder[pos]);
        node->left = build_tree_util(preorder, inorder, n, index+1, beg, pos-1);
        node->right = build_tree_util(preorder, inorder, n, index+pos-beg+1, pos+1, end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* root = build_tree_util(preorder, inorder, n, 0, 0, n-1);
        return root;
    }
};

//Time Complexity : O(n^2)
//Space Complexity : O(logn) - recursion call stack