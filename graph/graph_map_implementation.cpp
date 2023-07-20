#include <bits/stdc++.h>
using namespace std;

int main() {

 int n,m;
 cin>>n>>m;
 map<string,vector<pair<string,string>>> mp;
 map<string,pair<string,string>> p;
 
 for(int i=0;i<m;i++){
   string c1,c2,r;
   cin>>c1>>c2>>r;
   mp[c1].push_back(make_pair(c2,r));
 }
 
 string src,des;
 cin>>src>>des;

 map<string,bool> vis;
 for(auto it = mp.begin();it!=mp.end();it++){
    vis[it->first] = false;
 }
 p[src] = make_pair("","");


queue<string> q;
q.push(src);
vis[src]=true;
while(!q.empty()){
    string city = q.front();
    q.pop();
    for(auto neigbour : mp[city]){
        if(vis[neigbour.first]==false){
            p[neigbour.first] = make_pair(city,neigbour.second);
            vis[neigbour.first] = true;
            q.push(neigbour.first);
        }
    }
 }

 vector<string> path;

 string road = p[des].second;
string city  = des;
 while(road!=""){
    path.push_back(road);
    city = p[city].first;
    road = p[city].second;
 }


 int size = path.size();

if(size>0){
cout<<size<<endl;
reverse(path.begin(), path.end());
for(auto x : path){
    cout<<x<<endl;
}
}
else {
    cout<<"Impossible"<<endl;
}

}