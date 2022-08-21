 vector<int> leftView(Node *root)
{
    vector <int> d;
   // Your code here
   if(root==NULL) return d;
   queue<Node*> s;
    s.push(root);
    s.push(NULL);
    bool ok=true;
   while(!s.empty()){
       
       Node* node=s.front();
       s.pop();
       if(node) {
           if(ok){
           d.push_back(node->data);
               ok=false;
           }
           if(node->right) s.push(node->right);
           if(node->left) s.push(node->left);
       }
       else{
           if(!ok) ok=true;
           if(s.size()==0) break;
           else s.push(NULL);
       }
       
   }
   return d;
}