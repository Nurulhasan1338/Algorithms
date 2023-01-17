Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root==NULL) return root;
    if(root->data==X){
        
        // case1
        // if both childs are NULL
        if(!root->left && !root->right)
        {
        // simply deleting the node 
        delete root;
        return NULL;
        }
        
        // case2
        // if on one of the child is NULL
        
        // sub case 1 left is null
        if(!root->left && root->right){
            Node * temp=root->right;
            delete root;
            return temp;
        }
        // sub case 2 right is null
        if(root->left && !root->right){
            Node * temp=root->left;
            delete root;
            return temp;
        }
        
        // case3
        // if both children has sub tree
        // find min element in right sub tree
        int min;
        Node* temp=root->right;
        while(temp!=NULL){
            min=temp->data;
            temp=temp->left;
        }
        // replace min with current node
        root->data=min;
        root->right=deleteNode(root->right,min);
        return root;
        
    }
    else if(root->data>X){
        root->left=deleteNode(root->left,X);
        return root;
    }
    else{
        root->right=deleteNode(root->right,X);
        return root;
    }
}
