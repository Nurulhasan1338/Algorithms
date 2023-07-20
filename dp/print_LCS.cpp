//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    int f(string s,string p,int i,int j){
        if(i<0 || j<0) return 0;
        
        if(s[i]==p[j]) return 1 + f(s,p,i-1,j-1);
        
        return min(f(s,p,i-1,j),f(s,p,i,j-1));
    }
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.size();
        int m = s.size();
        
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        

        // how to print the LCS;
        string ans = "";
        int i=n;
        int j=m;
    while(i>0 && j>0){
        
        if(s[i-1]==s[j-1]){
            ans = s[i-1] +ans;
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                i--;
            }
            else{
                j--;
            }
        }
    }
        
       
       return ans;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends