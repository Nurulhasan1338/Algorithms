#include <iostream>
using namespace std;

class Node {

public:
    int val;
    Node* next;
    
    Node(int val) {
    this->val = val;
    this->next = nullptr;
    }
};

Node* swapNodes(Node* head, int k) {
        
        int n=0;
        Node* node  = head;
        Node* sode  = head;
        Node* eode  = head;
        while(node!=NULL){
            node=node->next;
            n++;
        }

        node = head;
        int end = n-k+1;
        int start = k;
        cout<<n<<endl;
        for(int i=0;i<start-1;i++){
            sode=sode->next;
        }

        cout<<sode->val<<endl;

        for(int i=0;i<end-1;i++){
            eode=eode->next;
        }
        cout<<eode->val<<endl;      
        int temp = sode->val;
        sode->val = eode->val;
        eode->val = temp;

        return head;
    }

void print(Node *head){


    Node * current = head;
    while (current != nullptr) {
        cout <<current->val<<"->";
        current = current->next;
    }
}
int main() {
    // Create the first node with val value 1
    Node* head = new Node(1);

    // Add nodes for values 2, 3, 4, 5
    Node* current = head;
    for (int i = 2; i <= 5; i++) {
        Node* newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }


    Node * head1 = swapNodes(head,2);

    print(head1);

    current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
