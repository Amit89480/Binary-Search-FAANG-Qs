class Solution {
public:
void traverseleft(Node *root, vector<int>&ans){
        
        if(!root || (!root->left && !root->right)) return;
        
        ans.push_back(root->data);
        
        if(root->left) traverseleft(root->left,ans);
        else traverseleft(root->right,ans);
    }
    
    void traverseleaf(Node *root, vector<int>&ans){
        
        if(!root) return;
        
        if(!root->left && !root->right) ans.push_back(root->data);
        
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
    }
    
    void traverseright(Node *root, vector<int>&ans){
        
        if(!root || (!root->left && !root->right)) return;
        
        if(root->right) traverseright(root->right,ans);
        else traverseright(root->left,ans);
        
        ans.push_back(root->data);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(!root) return ans;
        
        ans.push_back(root->data);
        
        //printing left part of tree
        traverseleft(root->left,ans);
        
        //printing leaf nodes
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
        
        //printing right part of tree
        traverseright(root->right,ans);
        
        return ans;
    }
};