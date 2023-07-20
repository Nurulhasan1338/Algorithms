#include <bits/stdc++.h>
using namespace std;


int main()
{

int n,x;
  cin>>n>>x;
  vector<vector<int>> gh(n+1);
  int cnt=0;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    gh[a].push_back(b); 
    if(a>b) cnt++; 
  }

  cout<<x*cnt<<endl;


return 0;
}