//Written by Nurul Hasan 2020kucp1009
#include <iostream>
#include <vector>
using namespace std;
 
 void generate_subsequence(int in,string str, string &curr,vector<string> &res){
    res.push_back(curr);
    for(int i=in;i<str.size();i++){
        curr.push_back(str[i]);
        generate_subsequence(i+1,str,curr,res);
        curr.pop_back();
    }

 }
int main(){

string str = "abc";
vector<string> res;
string temp = "";
generate_subsequence(0,str,temp,res);
for(int i=0;i<res.size();i++){
    cout<<" ,"<<res[i];
}

return 0;
}