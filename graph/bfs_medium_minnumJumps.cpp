#include <bits/stdc++.h>
using namespace std;



int bfs(vector<vector<int>> gh,int src,int dest){
    vector<int> vis(gh.size(),0);
    vector<int> dis(gh.size(),INT_MAX);
    queue<int> q;
    q.push(src);
    
    vis[src]=1;
    dis[src]=0;
    
    while(!q.empty()){
      int a = q.front();
      q.pop();
      for(auto x:gh[a]){
        if(vis[x]==0){
          vis[x]=1;
          dis[x] = dis[a]+1;
          q.push(x);
        }
      }
    }
    
    if(dis[dest]==INT_MAX) return 0;
    
    return dis[dest];
    
    
}
int main() {
  
  int n,m;
  cin>>n>>m;
  vector<vector<int>> gh(n+1);
  
  for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    gh[a].push_back(b);
    gh[b].push_back(a);
  }
  
  int src,dest;
  cin>>src>>dest;
  cout<<bfs(gh,src,dest);

  return 0;

}