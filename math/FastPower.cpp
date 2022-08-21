//Written by Nurul Hasan 2020kucp1009
#include <iostream>
#include <vector>
using namespace std;
int fastpower(int a,int  b){
    if(b==0) return 1;
    if(b&1==0) return fastpower(a*a,b>>1)%int(1e9+7);
    return a*fastpower(a,b-1)%int(1e9+7);

} 
int main(){

cout<<fastpower(3,102);

return 0;
}