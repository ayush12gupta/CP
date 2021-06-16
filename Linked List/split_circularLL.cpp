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

void splitCircular(Node* head, Node** headRef1, Node** headRef2) {
	Node* slow = head;
	Node* fast = head;
	if (head == NULL) return;

	while(fast->next != head && fast->next->next != head) {
		fast = fast->next->next;
		slow = slow->next;
	}
	// even nodes case
	if (fast->next->next == head) fast = fast->next;

	(*headRef1) = head; // head of the first half

	if (head->next != head) {
		*headRef2 = slow->next;
	}
	//Making the second half circular
	fast->next = slow->next;
	//Making the first half circular
	slow->next = head;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4); // 4->3->2->1
    print(&head);
    // Creating the link b/w the last node and first node
    head->next->next->next->next = head;
	Node *head1, *head2;
	splitCircular(head, &head1, &head2);
	cout<<head2->data;
	return 0;
}
