void solve(Node* root,vector<int> &ans,int level){
if(root==NULL)
return;

if(level==ans.size())
ans.push_back(root->data);
// if we want to see the right view of a binary tree just push root->left below the root->right and we can see the right view of a binary tree
solve(root->left,ans,level+1);
solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
  solve(root,ans,0);
  return ans;
}