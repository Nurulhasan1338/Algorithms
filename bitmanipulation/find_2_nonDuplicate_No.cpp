//Written by Nurul Hasan 2020kucp1009

#include <iostream>
#include <vector>
using namespace std;

 void find(vector <int> &vec){
    
    int x=0;
    int n=vec.size();
    for(int i=0;i<n;i++){ x=x^vec[i];}

    int y=x;
    int itr=0;

    while(y){
      if(y&1==1) break;
      y=y>>1;
      itr++;
    }
    
    vector <int> a,b;
    for(int i=0;i<n;i++){
      if((vec[i]>>itr) & 1 ==1) a.push_back(vec[i]);
      else b.push_back(vec[i]);
    }

int z=x;

     for(int i=0;i<a.size();i++)  z=(z^a[i]);
    int e=z^x;
     cout<<z<<" "<<e;
 }

int main(){

   vector<int> a;
  a={1,1,2,3,4,4,5,5};
   
   find(a);
return 0;
}