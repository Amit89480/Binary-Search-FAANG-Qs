class Solution {
  public:
     
    void createMap(Node* root,int target, map<Node*,Node*> &nodeToParent, Node* &targetNode){
          
          if(root->data == target){
              targetNode = root;
          }
          
          if(root == NULL || (root->left == NULL && root->right == NULL)){
              return;
          }
          if(root->left){
              nodeToParent[root->left] = root;
              createMap(root->left,target,nodeToParent,targetNode);
          }
          if(root->right){
              nodeToParent[root->right] = root;
              createMap(root->right,target,nodeToParent,targetNode);
          }
         
         
     }
     
     int burn(Node* targetNode, map<Node*,bool> &visited,map<Node*,Node*> &nodeToParent){
         
         int ans = 0;
         queue<Node*> q;
         
         q.push(targetNode);
         
         while(!q.empty()){
             
             int flag = 0;
             int size = q.size();
             
             for(int i =0;i<size;i++){
                 
                 Node* temp = q.front();
                 q.pop();
                 
                 visited[temp] = true;
                 
                 if(temp->left && !(visited[temp->left])){
                     q.push(temp->left);
                     visited[temp->left] = true;
                     flag = 1;
                 }
                 if(temp->right && !(visited[temp->right])){
                     q.push(temp->right);
                     visited[temp->right] = true;
                     flag = 1;
                 }
                 if(nodeToParent[temp] && !(visited[nodeToParent[temp]])){
                     q.push(nodeToParent[temp]);
                     visited[nodeToParent[temp]] = true;
                     flag = 1;
                 }
                 
             }
             
             if(flag == 1){
                 ans++;
             }
             
         }
         
         return ans;
         
         
     }
  
  
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        map<Node*,Node*> nodeToParent;
        map<Node*,bool> visited;
        
        nodeToParent[root] = NULL;
        
        Node* targetNode = NULL;
        
        createMap(root,target,nodeToParent,targetNode);
        return burn(targetNode,visited,nodeToParent);
        
    }
};