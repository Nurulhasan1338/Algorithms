   void count(Node* root,int &n){
       if(!root) return;
       count(root->left,n);
       n++;
       count(root->right,n);
   }
   int find(Node * root,int &i,int a){
       if(root==NULL) return -1;
       int l= find(root->left,i,a);
       if(l!=-1) return l;
       
       i++;
       if(i==a) return root->data;
       
       int r=find(root->right,i,a);
       if(r!=-1) return r;
       
   }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        int n = 0;
        // count all the node in the BST
        count(root,n);
        // now get its index value
        int a=n-K+1;
        // counter
        int i=0;
        
        return find(root,i,a);
    }