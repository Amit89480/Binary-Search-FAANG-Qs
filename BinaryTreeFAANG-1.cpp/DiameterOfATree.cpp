public:
    int diameterOfBinaryTree(TreeNode* root) {
        
    if(root==NULL){
        return 0;
    }
        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=maxDepth(root->left)+maxDepth(root->right);
        
        int ans=max(op1,max(op2,op3));
        return ans;
        
    }

    // /below is code for optimize approach
    class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    pair<int,int> diameterFast(Node* root){
        if(root==NULL){
            pair<int,int> p =make_pair(0,0);
            return p;
        }
        pair<int,int> left=diameterFast(root->left);
        pair<int,int> right=diameterFast(root->right);
        
        int op1=left.first;
        int op2=right.second;
        int op3=left.second+right.second +1;
        
        
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        return diameterFast(root).first;
    }
};