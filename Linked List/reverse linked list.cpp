#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void push(Node** headref, int data) {
    Node* new_node = new Node(data);
    new_node->next = (*headref);
    (*headref) = new_node;
}


void reverse_iter(Node **headref) {   // Iterative
    Node* curr = (*headref);
    Node *prev = NULL, *nxt = NULL;
    while(curr != NULL) {
        nxt = curr->next; // Next node
        curr->next = prev; // Reversing the current
        prev = curr;
        curr = nxt;
    }
    (*headref) = prev;
}

void print(Node **headref) {
    Node* curr = (*headref);
    while(curr != NULL) {
        cout<<curr->data;
        curr = curr->next;
        if (curr!=NULL)
            cout<<"-->";        
    }
}

Node* reverse_rec(Node *headref) {
    Node* head = (headref);
    if (head==NULL || head->next==NULL) return head;

    Node* rest = reverse_rec(head->next);
    //Correcting the direction of linked list in head and head->next    
    head->next->next = head;

    head->next = NULL;
    return rest;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head=NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 15); // 15->20->10
    cout<<"Before iterative reverse :";
    print(&head);   
    cout<<endl;
    reverse_iter(&head);
    cout<<"After iterative reverse :";
    print(&head);    
    cout<<endl;
    cout<<"--------------------------------\n";
    cout<<"Before recursive reverse :";
    print(&head);   
    cout<<endl;
    head = reverse_rec(head);
    cout<<"After recursive reverse :";
    print(&head);    
    cout<<endl;
return 0;
}
