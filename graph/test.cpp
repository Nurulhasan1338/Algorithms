// #include <bits/stdc++.h>
// using namespace std;

//     int dfs(int src,vector<vector<int>> &gh,vector<int> &vis,vector<int> &nodes){
//         vis[src]=1;
//         priority_queue<int,vector<int>,greater<int>> q;
//         for(auto x : gh[src]){
//             if(vis[x]==0){
//                 int temp = dfs(x,gh,vis,nodes);
//                if(q.size()>=2) {
//                 if(q.top()<temp) {
//                     q.pop();
//                     q.push(temp);
//                 }
//                }
//                else{
//                 q.push(temp);
//                }
                
//             }
//         }
//         int a=0,b=0;
//         if(q.size()>0) {
//             a = q.top();
//             q.pop();
//         }
//         if(q.size()>0){
//             b = q.top();
//             q.pop();
//         }
        
//         nodes[src] = a +b+1;
//         if(b!=0){
//             return 1+b;
//         } 
//         return 1+a;
//     }
// int main() {

//   int n;
//   cin>>n;
//   vector<vector<int>> gh(n+1);
  
//   for(int i=1;i<n;i++){
//     int a,b;
//     cin>>a>>b;
//     gh[a].push_back(b);    
//   }

//   vector<int> vis(n+1,0);
  
//     vector<int> nodes(n+1,0);
//     int num = dfs(1,gh,vis,nodes);

//     int ans=0;
//     for(auto x:nodes){
//         ans = max(x,ans);
//     }

//     cout<<ans<<endl;
    

//   return 0;

// }

// C++ program to find diameter of a binary tree
// using DFS.
#include <iostream>
#include <limits.h>
#include <list>
using namespace std;

// Used to track farthest node.
int x;

// Sets maxCount as maximum distance from node.
void dfsUtil(int node, int count, bool visited[],
				int& maxCount, list<int>* adj)
{
	visited[node] = true;
	count++;
	for (auto i = adj[node].begin(); i != adj[node].end(); ++i) {
		if (!visited[*i]) {
			if (count >= maxCount) {
				maxCount = count;
				x = *i;
			}
			dfsUtil(*i, count, visited, maxCount, adj);
		}
	}
}

// The function to do DFS traversal. It uses recursive
// dfsUtil()
void dfs(int node, int n, list<int>* adj, int& maxCount)
{
	bool visited[n + 1];
	int count = 0;

	// Mark all the vertices as not visited
	for (int i = 1; i <= n; ++i)
		visited[i] = false;

	// Increment count by 1 for visited node
	dfsUtil(node, count + 1, visited, maxCount, adj);
}

// Returns diameter of binary tree represented
// as adjacency list.
int diameter(list<int>* adj, int n)
{
	int maxCount = INT_MIN;

	/* DFS from a random node and then see
	farthest node X from it*/
	dfs(1, n, adj, maxCount);

	/* DFS from X and check the farthest node
	from it */
	dfs(x, n, adj, maxCount);

	return maxCount;
}

/* Driver program to test above functions*/
int main()
{
	int n;
    cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}

sort(vec.begin(),vec.end(),greater <>());
int ans=0;
for(int i=0;i<n;i=i+2)
	ans += vec[i]; 
  
  cout<<ans;
	
	return 0;
}
