#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf = 1e5;

int find(int i,int n,vector<int> &v){
  if(i==v.size()) return 0;
  if(n==0) return 0;
  if(n<0)  return INT_MIN;
   cout<<"ck2"<<endl;
  int a = v[i] + find(i,n-i+1,v);
   cout<<"ck4"<<endl;
  int b = v[i] + find(i+1,n-i+1,v);
  int c = find(i+1,n,v);
   cout<<"ck3"<<endl;
  return max(a,max(b,c));
}
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    int ans = find(0,n,v);
    cout<<"ck1"<<endl;
    cout<<ans<<endl;
    
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}