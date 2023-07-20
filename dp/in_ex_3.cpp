#include <bits/stdc++.h>
using namespace std;


 vector<vector<bool>> dp(200,vector<bool>(200,false));
  

bool find(int i,int s1,int s2,vector<int> &v){
  if(s1==s2 && s1!=0) return dp[s1][s2] = true;
  
  if(i>=v.size()) return false;
  
  if(dp[s1][s2]) return true;
  bool ans1 =find(i+1,s1+v[i],s2,v);
  
  if(ans1){
    return dp[s1+v[i]][s2]=true; 

  } 
  if(find(i+1,s1,s2+v[i],v)){
    dp[s1][s2+v[i]]=true;
  } 

  return false;

}

void solve(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
 
  
  if(find(0,0,0,v)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  
}
int main() {

  int t;
  cin>>t;
  while(t--){
    solve();
  }

  return 0;

}