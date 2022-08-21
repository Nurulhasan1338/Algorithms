
#include <iostream>
#include <vector>
using namespace std;
 
//  Creatinging adjacncy list 
    vector<int> createList(int v){
        vector<int> gh(v,0);
        for(int i=0;i<gh.size();i++){
            int des,src;
            cin>>src>>des;
            gh[src].push_back(des);
        }
        return gh;
    }

    // creatinging adacncy matrix
    vector<vector<int>> createMatrix(int v){
        vector<vector<int>> gh(v,vector<int> (v,0));
        while(true){
            int des;
            int src;
            cin>>src>>des;
            if(des==-1) break;
            gh[src,des] = 1;
            gh[des,src] = 1;
        }
        return gh;
    }
int main(){
    


return 0;
}