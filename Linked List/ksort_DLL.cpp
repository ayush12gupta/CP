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
    struct Node* prev;
    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void push(Node** headref, int data) {
    Node* new_node = new Node(data);
    new_node->next = (*headref);
    new_node->prev = NULL;

    if ((*headref)!=NULL) (*headref)->prev = new_node;
    (*headref) = new_node;
}

void print(Node **headref) {
    Node* curr = (*headref);
    if (curr == NULL)
        cout << "Doubly Linked list empty";

    while(curr != NULL) {
        cout<<curr->data;
        curr = curr->next;
        if (curr!=NULL)
            cout<<"-->";       
    }
    cout<<endl;
}

Node* Ksorted(Node* head, int k) {
	if (head==NULL || head->next==NULL) return head;
	Node *i;
	for (i=head->next; i!=NULL; i=i->next) {
		Node *j = i;
		// Loop to check if ptr2 value is less than ptr2->prev
		while (j->prev != NULL && j->data < j->prev->data) {
			Node* tmp = j->prev->prev;
			Node* tmp2 = j->prev;
			Node* tmp3 = j->next;
			j->prev->next = tmp3;
			j->prev->prev = j;
			j->prev = tmp;
			j->next = tmp2;
			if (tmp != NULL) {
				tmp->next = j;
			}
			if (tmp3 != NULL) {
				tmp3->prev = tmp2;
			}
		}

		if (j->prev == NULL) head = j;
	}
	return head;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    struct Node* head = NULL;
 
    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
 
    int k = 2;
 
    cout << "Original Doubly linked list:\n";
    // print(&head);

    Node* sorted = Ksorted(head, k);
    print(&sorted);
	return 0;
}
