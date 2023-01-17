//Written by Nurul Hasan 2020kucp1009
#include <iostream>
#include <vector>
using namespace std;
 class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        this->data=x;
        this->next=NULL;
    }
 };


 class stack{
    public:
    Node* top;

    stack(){
    this->top = NULL;
    }
    void push(int x){

        Node * newNode = new Node(x);
        if (!newNode) {
            cout << "\nStack Overflow";
            exit(1);
        }
       newNode->data=x;
       newNode->next = top;
       top = newNode;
    }

    void pop(){
        if(top==NULL){
            cout<<"stack is empty"<<endl;
            return;
        }
        else{
            top=top->next;
            // cout<<"popped!\n";
        }
    }
    int Top(){
        if(top==NULL){
           cout<<"stack is empty!\n";
        }
        return top->data;
    }
    bool isempty(){
        if(top==NULL) return true;
        return false;
    }

 };
int main(){

    stack s;
    s.push(3);
    s.push(2);
    s.push(4);
    s.push(4);
    s.push(4);
    s.push(4);
    s.push(4);
    s.push(4);
    s.push(4);
    // s.push(5);
    while(!s.isempty()){

    cout<<s.Top()<<" ";
    s.pop();
    }


return 0;
}