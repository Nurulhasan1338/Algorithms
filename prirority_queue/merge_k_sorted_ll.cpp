
// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they 
// will be a single sorted linked list.

// K = 4
// value = {{1,2,3},{4 5},{5 6},{7,8}}
// Output: 1 2 3 4 5 5 6 7 8
// Explanation:
// The test case has 4 sorted linked 
// list of size 3, 2, 2, 2
// 1st    list     1 -> 2-> 3
// 2nd   list      4->5
// 3rd    list      5->6
// 4th    list      7->8
// The merged list will be
// 1->2->3->4->5->5->6->7->8.

class myComparator
{
public:
    bool operator() (const Node* p1, const Node* p2)
    {
        return p1->data > p2->data;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    

    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
        priority_queue<Node*,vector<Node*>,myComparator> pq;
        
        for(int i=0;i<K;i++){
            pq.push(arr[i]);
        } 
        Node * head = new Node (-1);
        Node * tail = head;
        
        while(!pq.empty()){
            Node * node = pq.top();
            pq.pop();
            Node * newnode = new Node(node->data);
            tail->next = newnode;
            tail = newnode;
            if(node->next!=NULL){
                pq.push(node->next);
            }
        }
        
        return head->next;
           
    }
};

