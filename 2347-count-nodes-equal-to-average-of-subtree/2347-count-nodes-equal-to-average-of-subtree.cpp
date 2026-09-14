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
pair<int,int> inorder(TreeNode* root,int&answer){
    if(root==nullptr) return {0,0};

    pair<int,int> x=inorder(root->left,answer);
    pair<int,int> y=inorder(root->right,answer);

    int sum=root->val+x.first+y.first,size=1+x.second+y.second;
    int avg=sum/size;

    if(root->val==avg) answer++;

    return {sum,size};
}
    int averageOfSubtree(TreeNode* root) {
        int answer=0;
        inorder(root,answer);
        return answer;
    }
};