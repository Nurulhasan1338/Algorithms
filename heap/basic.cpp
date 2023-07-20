// heap insetion , deletion, and heap sort

//Written by Nurul Hasan 2020kucp1009
#include <iostream>
#include <vector>
#define len 10000
using namespace std;

class heap{
    int arr[len];
    int s;
    public:
    heap(){
        s=0;
        arr[0]=-1;
    }
    void heapify(int i){

        if(i>=s) return;

        int left = 2*i;
        int right = (2*i)+1;

        if(left<s && arr[left]>arr[i]){
            swap(arr[left],arr[i]);
            i =left;
        }
        else if(right<s && arr[right]>arr[i]){
            swap(arr[right],arr[i]);
            i =right;
        }
        else {
            return;
        }
        heapify(i);
    }
    void pop(){
        if(s==0) {
            cout<<"heap is empty\n";
            return;
        }
        arr[1]=arr[s];
        delete(&arr[s]);
        s=s-1;
        heapify(1);
     }

     int top(){
        if(s>0) return arr[1];
        return -1;
     }
    void push(int val){
        if(s>=len) {
            cout<<"heap is full\n";
            return;
        }
        s++;
        arr[s]=val;
        int i = s;
        while(i>1){
            int parent = i/2;
            if(parent>0 && arr[parent]<arr[i]){
                swap(arr[parent],arr[i]);
                i = parent;
            }
            else {
               break;
            }
        }
        for(int i=1;i<=s;i++){
            cout<<arr[i]<<", ";
        }
        cout<<"\n";
    }
    

};

int main(){
    heap h;
    h.push(4);
    h.push(2);
    h.push(61);
    h.push(1);
    h.push(8);
    h.push(5);
    h.push(0);
    h.pop();
    h.pop();
    cout<<h.top()<<endl;
    h.push(0);


return 0;
}