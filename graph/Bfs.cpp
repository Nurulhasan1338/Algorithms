//Written by Nurul Hasan 2020kucp1009
#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<list<int>> &adj,int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
       
}

void normalPrint(vector<int> gh[],int V){
     for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : gh[v])
            cout << "-> " << x;
        printf("\n");
    }
}

    void BFS(vector<list<int>> adj,int src,vector<int> &vis){
        // creating queue
        list<int> q;
        // making source visited
        vis[src]=1;
        // pushing it in queue a int not head of list
        q.push_back(src);
        // runnig the queu till is is not  empty
        while(!q.empty()){
            int node = q.front();
            // cout<<node<<" ";
            q.pop_front();
            for(auto x : adj[node]){
                if(vis[x]==0){
                    vis[x]=1;
                    q.push_back(x);
                }
            }
        }
    }
int main(){
    int V = 7;
    vector <list<int>> adj;
    adj.resize(V);
    addEdge(adj,1,2);
    addEdge(adj,3,6);
    addEdge(adj,4,5);
   
    vector <int> vis(V,0);
    vis[0]=1;
    int i=1;
    int count=0;
    
    while(true){
    count++;
    BFS(adj,i,vis);
    bool l = false;
    for(int j=1;j<V;j++) {
        if(vis[j]==0) {
        l=true;
        i=j;
        break;
        }}
    if(l==false) break;
    }
    cout<<count;
return 0;
}