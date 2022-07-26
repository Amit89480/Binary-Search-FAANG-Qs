class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    TreeNode* lowestCommonAncestor(TreeNode* root ,int n1 ,int n2 )
    {
     if(root==NULL){
         return NULL;
     } 
     if(root->val==n1||root->val==n2){
         return root;
     }
     TreeNode* leftans =lowestCommonAncestor(root->left,n1,n2);
     TreeNode* rightans= lowestCommonAncestor(root->right,n1,n2);
     if(leftans!=NULL&&rightans!=NULL){
         return root;
     }
     else if(leftans!=NULL&&rightans==NULL){
         return leftans;
     }
     else if(leftans==NULL&&rightans!=NULL){
         return rightans;
     }
     else{
         return NULL;
     }
    }
};