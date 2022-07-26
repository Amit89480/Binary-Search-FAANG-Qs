class Solution
{
   private:
   pair<bool,int> isSumTreeFast(Node*root){
   //Base Case
   if(root == NULL){
       pair<bool,int>p=make_pair(true,0);
       return p;
   }

   if(root->left == NULL && root->right == NULL){
       pair<bool,int>p=make_pair(true,root->data);
       return p;
   }

   pair<bool,int>leftAns = isSumTreeFast(root->left);
   pair<bool,int>RightAns = isSumTreeFast(root->right);

   bool left = leftAns.first;
   bool right = RightAns.first;
   
   int val1=leftAns.second;
   int val2=RightAns.second;

   bool condition=false;
   if(root->data == (val1+val2)){
       condition = true;
   }
   pair<bool,int>ans;

   if(left&&right&&condition){
       ans.first=true;
       ans.second = 2*root->data;
   }
   else{
       ans.first = false;
   }
   return ans;
   }
   public:
   bool isSumTree(Node* root)
   {
       return isSumTreeFast(root).first;
   }
};