#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &gh,vector<int> deg,int src,int &c){
  
  queue<int> q;
  q.push(src);
  vector<int> vis(gh.size(),0);
  vis[src]=1;
  c=1;
  
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(auto x : gh[curr]){
      if(vis[x]==0){
        c++;
        vis[x]=1;
        if(deg[x]!=1) return false;
        q.push(x);
      }
    }
  }
  
  return true;
  
}
int main() {
    int n, m;
    cin >> n >> m;

 vector<vector<int>> gh(n+1);
 vector<int> deg(n+1, 0);
    for (int i = 1; i <= m; i++) {
      int a,b;
      cin >> a >> b;
      gh[a].push_back(b);
      gh[b].push_back(a);
      deg[a]++;
      deg[b]++;
    }
  
  vector<int> pt;
    for (int i = 1; i <=n; i++) {
        if (deg[i] != 1) {
           pt.push_back(i);
        }
    }
    
    int count=0;
    
    vector<int> nc;
    for(int i=0;i<pt.size();i++){
      int c=0;
      if(bfs(gh,deg,pt[i],c)){
        count++;
        if(find(nc.begin(),nc.end(),c)==nc.end()) nc.push_back(c);
        else {
          count--;
        }
      }
      
    }
    
    cout << count << endl;

    return 0;
}
