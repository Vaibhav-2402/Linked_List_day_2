#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    //Destrutor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    cout << "The memory is freed for : " << value << endl;
    }
};

void InsertAtHead(Node* &head, int data){
    // creating a new node
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &tail, Node* &head, int data, int position){
    if(position == 1){
        InsertAtHead(head, data);
        return;
    }
    
    Node* temp = head;
    int count = 1;
    
    while(count < position-1){
        temp = temp -> next;
        count++;
    }
    
    if(temp -> next == NULL){
        InsertAtTail(tail, data);
        return;
    }
    
    //Inserting at middle position
    Node* NodeToInsert = new Node(data);
    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
}

void DeleteNode(int position, Node* &head){
    
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else {
    // for middle and last node
    int cnt = 1;
    Node* curr = head;
    Node* prev = NULL;
    
    while(cnt < position) {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }
    
    prev->next = curr->next;
    curr -> next = NULL;
    delete curr;
    }
}
void print(Node* &head) {
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp -> data << "  ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    
    Node* node1 = new Node(89);
    
    //cout << node1->data << endl;
    //cout << node1->next << endl;
    
    Node* head = node1;
    
    Node* tail = node1;
    
    InsertAtTail(tail, 56);
    print(head);
    
    InsertAtTail(tail, 986);
    print(head);
    InsertAtPosition(tail, head, 235, 4);
    print(head);
    
    InsertAtPosition(tail, head, 998, 2);
    print(head);
    
    DeleteNode(1, head);
    print(head);
    return 0;
}