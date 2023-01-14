# include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    //constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int value = this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with data: "<<value<<endl;
    }
};

//traversing a LL
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//finding length of LL
int getLength(Node* &head){
    Node* temp = head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
} 

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPos(Node* &tail,Node* &head,int pos, int d){
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    else{
        Node* temp = head;
        --pos;
        while(--pos){
            temp=temp->next;
        }
        if(temp->next==NULL){
            insertAtTail(tail,d);
            return ;
        }
        //creating new node
        Node* newNode = new Node(d);
            // cout<<"check11";
        newNode->next= temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

//using loop
Node* ReverseDLL(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
        curr->prev=curr->next;
        curr->next=prev;
        prev=curr;
        curr=curr->prev;
    }
    return prev;
}

//using recursion - DUE

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    print(head);
    cout<<getLength(head)<<endl;

    insertAtHead(head,11);
    print(head);

    insertAtHead(head,13);
    print(head);

    insertAtHead(head,8);
    print(head);

    insertAtTail(tail,25);
    print(head);

    insertAtPos(tail,head,2,100);
    print(head);

    insertAtPos(tail,head,1,101);
    print(head);

    insertAtPos(tail,head,8,102);
    print(head);

    head = ReverseDLL(head);
    print(head);

    return 0;
}