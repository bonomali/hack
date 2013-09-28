/*
 * Given root of a tree, return linked lists of every level
 * Cracking the code 4.4
 */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        if (root == NULL) return result;
        vector<vector<TreeNode*>> nodes;
        int level = 0;
        vector<int> vec;
        vector<TreeNode*> vecNode;
        vec.push_back(root->val);
        vecNode.push_back(root);
        result.push_back(vec);
        nodes.push_back(vecNode);
        while(!result[level].empty()){
            vector<int> l;
            vector<TreeNode*> lnode;
            for (int i = 0; i < nodes[level].size(); i++){
                TreeNode* node = nodes[level][i];
                if(node->left) {
                    lnode.push_back(node->left);
                    l.push_back(node->left->val);
                }
                if(node->right) {
                    lnode.push_back(node->right);
                    l.push_back(node->right->val);
                }
            }
            nodes.push_back(lnode);
            //if (!l.empty())
            result.push_back(l);
            level++;
        }
        result.pop_back();
        return result;
    }
};
