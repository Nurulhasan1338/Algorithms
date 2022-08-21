void getleft(Node* root,vector<int> &d,int l,int* c_level){
    
    if(root==NULL) return;
    // to check weather it is first element or not 
    // if it is first element then it will update the c_level
    if(*c_level<l){
        d.push_back(root->data);
        *c_level=l;
    }
    // Here will not pass the pointer because we do not want the updated value from left sub tree
    getleft(root->left,d,l+1,c_level);
    getleft(root->right,d,l+1,c_level);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> res;
   // Your code here
   if(root==NULL) return res;
   int level=0;
   getleft(root,res,1,&level);
   
  
   return res;

  
}