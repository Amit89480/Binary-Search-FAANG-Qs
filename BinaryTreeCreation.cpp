#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root)
{

    cout << "Enter the data for Node: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for left: " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right:" << data << endl;
    root->right = buildTree(root->right);
    return root;
}
// here we are doing the levelordertravesal also with segmentation for printing with binary tree format
void levelordertraversal(Node* root ){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    
    while(!q.empty()){
        Node* temp = q.front();
       
        q.pop();

        if(temp==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
             cout << temp->data << " ";
             if(temp->left){
            q.push(temp->left);
        }
         if(temp->right){
            q.push(temp->right);
        }
    }
    }

        
       
}
//1,3,7,-1,-1,11,-1,-1,5,17,-1,-1,-1

// inorder traversal by LNR

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ,";
    inorder(root->right);
}

// Preorder Traversal by NLR

void preorder(Node* root){
    if(root==NULL){
        return;
    }
      cout << root->data << " ,";
    preorder(root->left);
  
    preorder(root->right);
}

// below code is for posr order traversal

void postorder(Node* root){
    if(root==NULL){
        return;
    }
      
    postorder(root->left);
  
    postorder(root->right);
    cout << root->data << " ,";
}
// here actually we are making the root node
// yaha mujhse return nahi karana jo bhi root node aayegi uski ko refernce leke return kara dena hai isliye pass by refernec ka use krrhe

 void  buildfromlevelorder(Node* &root){
    queue <Node *> q;
    cout << "Enter data for root:" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        // yaha humlog front se nikaal ke left aur right mein push krrhe hai
        q.pop();
// here we are inserting the data for left node
        cout << "Enter left node for:" << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if(leftdata!=-1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }
// here we are inserting the data for right node
        cout << "Enter right node data:" << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if(rightdata!=-1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{

    
    Node *root = NULL;
    buildfromlevelorder(root);

    // root = buildTree(root);
    // // 1,3,7,-1,-1,11,-1,-1,5,17,-1,-1,-1
    // cout << "Printing the level order travesal"<<endl;
    levelordertraversal(root);
    // cout << "Below is inorder Travsersal" << endl;
    // inorder(root);
    // cout << "Below is preorder Travsersal" << endl;
    // preorder(root);
    // cout << "Below is postorder Travsersal" << endl;
    // postorder(root);
    return 0;
}