//Written by Nurul Hasan 2020kucp1009
#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
  string findSum(string X, string Y) {
        // Your code goes here
        int a=1;
        int c=0;
        string s="";
        int i=X.size()-1;
        int j=Y.size()-1;
        
        while(i>=0 && j>=0){
       
        int x = (X[i]-'0' + Y[j]-'0') + c;
        
        if(x>9) c=1;
        else c=0;
        x=x%10;
        string z=to_string(x);
        s.insert(0,z);
      
        i--;
        j--;
        
        }

        while(i>=0) {
            int q=(X[i]-'0')+c;
         
            if(q>9) {
                c=1;
            }
            else{
                c=0;
            }
            q=q%10;
             string z=to_string(q);
                s.insert(0,z);
            
            i--;
        }

        while(j>=0) {
          int q=(Y[j]-'0')+c;
            if(q>9) {
                c=1;
            }
            else{
                c=0;
            }
            q=q%10;
           
            string z=to_string(q);
            s.insert(0,z);
       
            j--;
        } 

        if(c==1) s.insert(0,"1");
        i=0;
      int cnt=0;
      while(s[i]=='0' && i<s.size()-1)
      {
          i++;cnt++;
      }
      s.erase(0,cnt);
        return s;
        
    }
int main(){

    string s1="000000000000000000";
    string s2="00000000000000000";
    cout<<endl<<findSum(s1,s2);

return 0;
}