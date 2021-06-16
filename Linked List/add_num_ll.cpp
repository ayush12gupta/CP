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
	if (head==NULL || head->next==NULL) return head;
	Node* rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;	
	return rest;
}

Node* addnums(Node* head1, Node* head2) {
	Node* head = NULL;
	Node *tmp, *prev = NULL;
	int carry = 0, sum;
	while (head1 != NULL || head2 != NULL) {
		sum = carry + (head1?head1->data:0) + (head2?head2->data:0);
		carry = (sum >= 10)?1:0;
		sum = sum % 10;
		tmp = new Node(sum);
		if (head == NULL) head = tmp;
		else prev->next = tmp;

		prev = tmp;

		if (head1) head1 = head1->next;
		if (head2) head2 = head2->next;
	}
	if (carry > 0) {
		tmp->next = new Node(carry);
	}
	return head;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head1 = NULL;
    push(&head1, 4);
    push(&head1, 5);
    push(&head1, 3);
    print(&head1);
    Node* head2 = NULL;
    push(&head2, 4);
    push(&head2, 3);
    print(&head2);
    head1 = reverse(head1);
    head2 = reverse(head2);
    cout<<"After reversing the linked list\n";
    print(&head1);
    print(&head2);
    Node* head = addnums(head1, head2);
    head = reverse(head);
    print(&head);
	return 0;
}
