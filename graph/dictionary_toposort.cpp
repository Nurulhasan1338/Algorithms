#include<bits/stdc++.h>
using namespace std;


void dfs(unordered_map<char,vector<char>> &gh,stack<char> &nodes,unordered_map<char,bool> &vis,char src){
        vis[src]=true;
        for(auto x : gh[src]){
            if(!vis[x]) dfs(gh,nodes,vis,x);
        }
        nodes.push(src);
    }


    string findOrder(string dict[], int N, int K) {
        //code here
        
        unordered_map<char,vector<char>> gh;
        unordered_map<char,bool> vis;
        
        for(int i=0;i<N-1;i++){
            int j=0;
            int k=0;
            string s1 = dict[i];
            string s2 = dict[i+1];
            while(j<s1.size() && k<s2.size()){
                if(s1[j]==s2[k]){
                    j++;
                    k++;
                    continue;
                }
                gh[s1[j]].push_back(s2[k]);
                cout<<s1[j]<<" ";
                for(auto x : gh[s1[j]]){
                    cout<<x<<" ";
                }
                cout<<endl;
                vis[s1[j]]=false;
                vis[s2[k]]=false;
                break;
            }
        }

        stack<char> nodes;
        
        for(auto it = gh.begin();it!=gh.end();it++){
            cout<<it->first<<endl;
            if(!vis[it->first])  dfs(gh,nodes,vis,it->first);
            
        }        
      
            string ans="";
            int size = nodes.size();
            for(int i=0;i<size;i++){
                cout<<nodes.top()<<endl;
                ans = ans + nodes.top();
                nodes.pop();
            }
       
        cout<<ans<<endl;
        return ans;
               
    }


int main(){
    int N,K;

    cin>>N>>K;

    string dict[N];

    for(int i=0;i<N;i++){
        cin>>dict[N];
    }

    cout<<findOrder(dict,N,K);
}