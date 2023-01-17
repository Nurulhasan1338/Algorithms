void convert_BST_To_DLL(Node * root,Node * &head,Node * &prev){
        
        if(root==NULL) return;
        convert(root->left,head,prev);
        
        if(prev==NULL) head = root;
        
        else{
        root->left=prev;
        prev->right=root;
        }
        prev=root;
        convert(root->right,head,prev);
    }
    
    
    Node * Merge_two_dll(Node* head1,Node* head2){
        Node * headm=NULL;
        Node * tail=NULL;
        
        while(head1!=NULL && head2!=NULL ){
        if(head1->data<head2->data){
              if(headm==NULL){
                  headm=head1;
                  tail=head1;
                  head1=head1->right;
              }
              else{
                  
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
                      
                  }
            }
            else{
               if(headm==NULL){
                  headm=head2;
                  tail=head2;
                  head2=head2->right;
              }
              else{
                  
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
                      
                }
            }
            
        }
        
        while(head1!=NULL){
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
        }
        
        while(head2!=NULL){
            tail->right=head2;
            head2->left=tail;
            tail=head2;
            head2=head2->right;
        }
        tail->right=NULL;
        return headm;
    }
    
    vector<int> merge_Two_bst(Node *root1, Node *root2)
    {
       //Your code here
       Node * head1 = NULL;
       Node * prev1 = NULL;
       
        convert(root1,head1,prev1);
       head1->left=NULL;
       
       Node * head2 = NULL;
       Node * prev2 = NULL;
      convert(root2,head2,prev2);
       head2->left=NULL;
       
       Node * headm = Merge(head1,head2);
       
      vector<int> ans;
      while(headm!=NULL){
          ans.push_back(headm->data);
          headm=headm->right;
      }
      return ans;
    }