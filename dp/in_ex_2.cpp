#include <bits/stdc++.h>
using namespace std;
#define l long int
#define mod 1000000007



//  apporach 1 memoization
int find(int i,int T,vector<int> &v, vector<vector<int>> &dp){
  if(T==0) return dp[i][T] = 1;
  if(T<0 || i==v.size()) return 0;
  
  if(dp[i][T]!=-1) return dp[i][T];
  l inc = find(i,T-v[i],v,dp)%mod;
  l xnc = find(i+1,T,v,dp)%mod;
  
  return dp[i][T] = (inc+xnc)%mod;
  
}
void solve(){
  int n,T;
  cin>>n>>T;
  vector<int> v(n);
  vector<vector<int>> dp(n+1,vector<int> (T+1,-1));
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  
  long long int ans  = find(0,T,v,dp)%mod;

  cout<<ans<<endl;
}

int main() {

  int t;
  cin>>t;
  while(t--){
  solve();
}
  return 0;

}



// Bottom up approach

void solve1()
{
    int n,s;
    cin>>n>>s;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    //Dp[i] = Total number of combinations of blocks such that the sum of picked blocks in each combination is equal to i.
    vector<int> dp(s+1,0);
    dp[0]=1;    //base case. Only way to make sum = 0 is by picking no blocks. 
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=s; j++)
        {
            if(j-v[i]>=0)
            {
                dp[j]+=dp[j-v[i]];
                dp[j]%=mod;
            }
        }
    }

    cout<<dp[s]<<"\n";
}
