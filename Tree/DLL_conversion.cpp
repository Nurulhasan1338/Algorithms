class Solution
{   
    public: 

    Node * head=NULL;
    Node * prev=NULL;
 
    //Function to convert binary tree to doubly linked list and return it.
    void convert(Node * root){
        // base case
        if(root==NULL) return;
        // inorder traversal
        convert(root->left);
        // if prev is null after above operation on left
        if(prev==NULL) head = root;
        //  else if will connect left leg of current root to the prev node which come fromm above opperstion
        // and right leg of prev node to connect to the current node
        else{
        root->left=prev;
        prev->right=root;
        }
        // now make the current root node to prev node
        prev=root;
        
        convert(root->right);
    }

    Node * bToDLL(Node *root)
    {
        
        convert(root);
        return head;
    }
};