//Written by Nurul Hasan 2020kucp1009
#include <iostream>
#include <vector>
using namespace std;

class stack {
    public:
    int size;
    int top;
    int * arr;
    stack(int size){
        this->size=size;
        this->top=-1;
        this->arr=new int[size];
    }
    void push(int x){
        if(top>=size){
            cout<<"stack overflow!\n";
            return;
        }
        if(top==-1) {
        top++;
        arr[top]=x;
        return;
        }
        if(arr[top]>x){
        top++;
        arr[top]=x;
        return;
        }
        else{
            int temp=arr[top];
            arr[top++]=x;
            arr[top]=temp;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"stack underflow!\n";
            return;
        }
        // delete(arr[top]);
        top--;
    }
    int peek(){
        if(top==-1){
            return -1;
        }
        return arr[top];

    }
};
 
int main(){
stack s(6);
s.push(-3);
s.push(2);
s.push(5);
s.push(1);
s.push(0);

// s.pop();
cout<<s.peek();
return 0;
}