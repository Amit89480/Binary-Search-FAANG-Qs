// build tree form inorder and preorder

class Solution{
    public:
    int findPosition(int in[],int element,int n){
        for (int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int n){
        if(index>=n||inorderstart>inorderend){
            return NULL;
        }
        int element=pre[index++];
    Node* root=new Node(element);
    int position=findPosition(in,element,n);
    
    root->left=solve(in,pre,index,inorderstart,position-1,n);
    root->right=solve(in,pre,index,position+1,inorderend,n);
    
    return root;
    
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorder=0;
        Node* ans=solve(in,pre,preorder,0,n-1,n);
        return ans;
    }
};