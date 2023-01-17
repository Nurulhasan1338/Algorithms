 vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node * i=head;
        int x=1,y=1;
        Node * j=head;
        vector<pair<int,int>> ans;
        
        if(head==NULL) return ans;
        
        while(j->next!=NULL){
            j=j->next;
            y++;
        }
        while(x<y){
            int s = i->data + j->data;
            if(s>target){
                j=j->prev;
                y--;
            }
            else if(s<target){
                i=i->next;
                x++;
            }
            else{
            ans.push_back({i->data,j->data});
            i=i->next;
            j=j->prev;
            x++;
            y--;
                
            }
        }
        return ans;
    }