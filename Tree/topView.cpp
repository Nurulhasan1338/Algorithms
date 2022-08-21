 vector<int> topView(Node *root)
    {
   vector <int> d;
   if(root==NULL) return d;
   unordered_map<int,int> map;
   queue<pair<Node*,int>> q;
   
    q.push({root,0});
    int min=INT_MAX;
    int max=INT_MIN;
    
   while(!q.empty()){
       
       pair<Node*,int> p = q.front();
       q.pop();
        int data=p.first->data;
        int hr=p.second;
        if(hr<min) min=hr;
        if(hr>max) max=hr;
        if(map[hr]==NULL) map[hr]=data;
        
           if(p.first->left!=NULL) q.push({p.first->left,hr-1});
           if(p.first->right!=NULL) q.push({p.first->right,hr+1});
       
   }
   for(int i=min;i<=max;i++){
       d.push_back(map[i]);
   }
   return d;
    }