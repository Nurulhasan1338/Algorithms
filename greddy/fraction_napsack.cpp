class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,Item> a,pair<double,Item> b){
        return a.first > b.first;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,Item>> v;
        for(int i=0;i<n;i++){
            double peru = (1.0*arr[i].value)/arr[i].weight;
            pair<double,Item> p = make_pair(peru,arr[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        
       double ans=0;
       
       for(int i=0;i<n;i++){
           if(v[i].second.weight>W){
               ans +=W*v[i].first;
               W=0;
           }
           else{
               ans += v[i].second.value;
               W = W - v[i].second.weight;
        }
       }
     return ans;
        
    }
};