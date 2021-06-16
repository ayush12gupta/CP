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
    int flag;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
        this->flag = 0;
    }
};

void push(Node** headref, int data) {
    Node* new_node = new Node(data);
    new_node->next = (*headref);
    (*headref) = new_node;
}

void print(Node **headref) {
    Node* curr = (*headref);
    while(curr != NULL) {
        cout<<curr->data;
        curr = curr->next;
        if (curr!=NULL)
            cout<<"-->";       
    }
    cout<<endl;
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef) {
    Node *fast, *slow;
    slow = source;
    fast = source->next;

    while(fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

Node* SortMerging(Node* a, Node* b) {
    Node* merged = NULL;

    if (a==NULL) return b;
    if (b==NULL) return a;

    if (a->data <= b->data) {
        merged = a;
        merged->next = SortMerging(a->next, b);
    }
    else {
        merged = b;
        merged->next = SortMerging(a, b->next);
    }

    return merged;
}

void MergeSort(Node** headRef) {
    Node* head = *headRef;
    Node *a, *b;

    if (head==NULL || head->next==NULL) {
        return;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortMerging(a, b);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, 5);
    push(&head, 2);
    push(&head, 6);    
    push(&head, 7);
    push(&head, 8);
    push(&head, 3);
    push(&head, 4);
    print(&head);
    MergeSort(&head);
    print(&head);
return 0;
}
