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

Node* reverse(Node* head) {
	if(head==NULL || head->next==NULL) return head;
	Node* rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

void addOne(Node* head) {
	Node* curr = head;
	int carry = 1;
	while(curr!=NULL && carry) {
		carry = (curr->data+1)/10;
		curr->data = (curr->data + 1)%10;
		curr = curr->next;
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, 4);
    push(&head, 5);
    push(&head, 3);
    print(&head);
    head = reverse(head);
    addOne(head);
    head = reverse(head);
    print(&head);
	return 0;
}
